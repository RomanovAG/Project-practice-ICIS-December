#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>
#include "logictypes.h"
#include "logicalelement.h"
#include "net.h"
#include "input_output.h"
#include "methods.h"
#include "graphicsscene.h"
using namespace std;

extern level_t logic_level;
extern vector<LogicalElement *> all_elements;
extern vector<Input_Output *> all_inOutputs;
extern vector<Net *> all_nets;

static int randomBetween(int low, int high)
{
    return (QRandomGenerator::global()->generate() % ((high + 1) - low) + low);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    QObject::connect(&this->form_SLL, &Set_logic_level::logicLevelChanged, this, &MainWindow::onLogicLevelChanged);
    ui->setupUi(this);
    QString title = "LogiTect";
    //title = title + QString::number(logic_level);
    setWindowTitle(title);
    logic_status = new QLabel(this);
    logic_status->setText("Logic level: undefined");
    ui->statusBar->addWidget(logic_status, 1);
    this->resize(1280,720);

    scene = new GraphicsScene(this);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);

    ui->graphicsView->setMinimumSize(500, 500);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setCacheMode(QGraphicsView::CacheBackground);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    scene->setSceneRect(QRect(0, 0, 1920, 1080));
    //Cache *cache = new Cache;
    //scene->addItem(cache);
    for (auto i = 0; i <= 1920; i += 40)
        scene->addLine(i, 0, i, 1080, QPen(Qt::darkGray));
    for (auto i = 0; i <= 1080; i += 40)
        scene->addLine(0, i, 1920, i, QPen(Qt::darkGray));
    ui->tab->setEnabled(false);
    ui->pushButton->setEnabled(false);
    ui->addNet->setEnabled(false);
    ui->addInOut->setEnabled(false);
    ui->connector->setEnabled(false);
}

MainWindow::~MainWindow() {
    delete ui; }

void MainWindow::connectSlot(std::vector<id_t> ids)
{
    Net *net = new Net;
    net->Net_ID = findNID(all_nets);
    net->value = 0;
    net->start_addr.first = ids[0];
    net->end_addr.first = ids[1];
    net->showForm();
    scene->addItem(net);
    all_nets.push_back(net);
    if (all_nets.size() > 1)
        sort(all_nets.begin(), all_nets.end(), compNID);
    for (id_t i = 0; i < all_elements.size(); i++)
    {
        all_elements[i]->setOpacity(1);
        all_elements[i]->setScale(1);
    }
}

void MainWindow::on_pushButton_clicked()
{
    LogicalElement *el = new LogicalElement;
    el->L_ID = findLID(all_elements);
    QObject::connect(el, &LogicalElement::connectSignal, this, &MainWindow::connectSlot);
    all_elements.push_back(el);
    if (all_elements.size() > 1)
        sort(all_elements.begin(), all_elements.end(), compLID);
    el->setPos(randomBetween(30, 200), randomBetween(30, 200));
    scene->addItem(el);
    ui->addNet->setEnabled(true);
    ui->addInOut->setEnabled(true);
}

void MainWindow::on_addNet_clicked()
{
    if (all_elements.size() < 1)
        return;
    Net *net = new Net;
    net->Net_ID = findNID(all_nets);
    net->value = 0;
    all_nets.push_back(net);
    if (all_nets.size() > 1)
        sort(all_nets.begin(), all_nets.end(), compNID);
    net->form_NP.show();
    scene->addItem(net);
}

void MainWindow::on_actionSet_logic_level_triggered()
{
    if (all_elements.size() == 0 && all_inOutputs.size() == 0 && all_nets.size() == 0)
        this->form_SLL.show();
}

void MainWindow::onLogicLevelChanged(level_t value)
{
    logic_level = value;
    this->logic_status->setText("Logic level: " + QString::number(logic_level));
    ui->tab->setEnabled(true);
    if (logic_level == 2)
        ui->tab_1->setEnabled(true);
    else
        ui->tab_1->setEnabled(false);
    if (logic_level == 3)
        ui->tab_2->setEnabled(true);
    else
        ui->tab_2->setEnabled(false);
    ui->pushButton->setEnabled(true);
    ui->connector->setEnabled(true);
}

void MainWindow::on_pushButton_2_clicked()
{
    updateScheme();
}


void MainWindow::on_notButton_clicked()
{
    LogicalElement *el = new LogicalElement;
    el->L_ID = findLID(all_elements);
    el->height = 60;
    el->width = 60;
    QObject::connect(el, &LogicalElement::connectSignal, this, &MainWindow::connectSlot);
    all_elements.push_back(el);
    if (all_elements.size() > 1)
        sort(all_elements.begin(), all_elements.end(), compLID);
    el->setPos(randomBetween(30, 200), randomBetween(30, 200));
    scene->addItem(el);
    ui->addNet->setEnabled(true);
    ui->addInOut->setEnabled(true);
    {
        el->L_inputs.resize(1);
        el->L_outputs.resize(1);
        el->L_name = "NOT";
        vector<vector<value_t>> output_table ((rows_t) pow(logic_level, el->L_inputs.size()), vector<value_t> (el->L_outputs.size()));
        el->T_outputs = output_table;
        auto input_num = el->L_inputs.size();
        auto output_num = el->L_outputs.size();
        auto rows = (rows_t) pow(logic_level, input_num);
        for (unsigned row = 0; row < rows; row++)
        {
            for (unsigned column = 0; column < output_num; column++)
            {
                el->T_outputs[row][column] = !row;
            }
        }
    }
}


void MainWindow::on_andButton_clicked()
{
    LogicalElement *el = new LogicalElement;
    el->L_ID = findLID(all_elements);
    QObject::connect(el, &LogicalElement::connectSignal, this, &MainWindow::connectSlot);
    all_elements.push_back(el);
    if (all_elements.size() > 1)
        sort(all_elements.begin(), all_elements.end(), compLID);
    el->setPos(randomBetween(30, 200), randomBetween(30, 200));
    scene->addItem(el);
    ui->addNet->setEnabled(true);
    ui->addInOut->setEnabled(true);
    {
        el->L_inputs.resize(2);
        el->L_outputs.resize(1);
        el->L_name = "AND";
        vector<vector<value_t>> output_table ((rows_t) pow(logic_level, el->L_inputs.size()), vector<value_t> (el->L_outputs.size()));
        el->T_outputs = output_table;
        auto input_num = el->L_inputs.size();
        //auto output_num = el->L_outputs.size();
        auto rows = (rows_t) pow(logic_level, input_num);
        for (unsigned i = 0; i < rows - 1; i++)
            el->T_outputs[i][0] = 0;
        el->T_outputs[3][0] = 1;
    }
}


void MainWindow::on_orButton_clicked()
{
    LogicalElement *el = new LogicalElement;
    el->L_ID = findLID(all_elements);
    QObject::connect(el, &LogicalElement::connectSignal, this, &MainWindow::connectSlot);
    all_elements.push_back(el);
    if (all_elements.size() > 1)
        sort(all_elements.begin(), all_elements.end(), compLID);
    el->setPos(randomBetween(30, 200), randomBetween(30, 200));
    scene->addItem(el);
    ui->addNet->setEnabled(true);
    ui->addInOut->setEnabled(true);
    {
        el->L_inputs.resize(2);
        el->L_outputs.resize(1);
        el->L_name = "OR";
        vector<vector<value_t>> output_table ((rows_t) pow(logic_level, el->L_inputs.size()), vector<value_t> (el->L_outputs.size()));
        el->T_outputs = output_table;
        auto input_num = el->L_inputs.size();
        //auto output_num = el->L_outputs.size();
        auto rows = (rows_t) pow(logic_level, input_num);
        el->T_outputs[0][0] = 0;
        for (unsigned i = 1; i < rows; i++)
            el->T_outputs[i][0] = 1;
    }
}


void MainWindow::on_addInOut_clicked()
{
    Input_Output *io = new Input_Output;
    io->IO_ID = findIOID(all_inOutputs);
    //QObject::connect(io, &LogicalElement::connectSignal, this, &MainWindow::connectSlot);
    all_inOutputs.push_back(io);
    if (all_inOutputs.size() > 1)
        sort(all_inOutputs.begin(), all_inOutputs.end(), compIOID);
    io->setPos(randomBetween(30, 200), randomBetween(30, 200));
    scene->addItem(io);
    io->formIOP.show();
}

void MainWindow::on_connector_clicked()
{
    LogicalElement *el = new LogicalElement;
    el->L_ID = findLID(all_elements);
    el->is_connector = true;
    all_elements.push_back(el);
    if (all_elements.size() > 1)
        sort(all_elements.begin(), all_elements.end(), compLID);
    el->setPos(randomBetween(30, 200), randomBetween(30, 200));
    scene->addItem(el);
    ui->addNet->setEnabled(true);
    ui->addInOut->setEnabled(true);
    auto rows = (rows_t) pow(logic_level, el->L_inputs.size());
    vector<vector<value_t>> input_table (rows, vector<value_t> (el->L_inputs.size()));
    for (unsigned i = 0; i < rows; i++)
    {
        auto current_row = i;
        for (int j = el->L_inputs.size() - 1; j >= 0; j--)
        {
            input_table[i][j] = current_row % logic_level;
            current_row /= logic_level;
        }
    }
    el->T_outputs = input_table;
    el->update();
}
