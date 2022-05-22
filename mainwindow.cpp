#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include <QtWidgets>
#include "logictypes.h"
#include "logicalelement.h"
#include "net.h"
#include "input_output.h"
#include "methods.h"
#include "el_to_save_form.h"
using namespace std;

extern vector<id_t> inputs_ids, outputs_ids;
long el_index_to_save;
QString lib_file;

extern QString current_file;
extern level_t logic_level;
extern ticker_t ticker;
extern vector<LogicalElement *> all_elements;
extern vector<Input_Output *> all_inOutputs;
extern vector<Net *> all_nets;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    lib_file = "";
    el_index_to_save = -1;
    QObject::connect(&this->form_SLL, &Set_logic_level::logicLevelChanged, this, &MainWindow::onLogicLevelChanged);
    QObject::connect(&this->form_ETS, &el_to_save_form::box_value, this, &MainWindow::saveElById);
    this->ui->setupUi(this);
    QString title = "LogiTect";
    if (current_file != "")
        title = "LogiTect | " + current_file;
    this->setWindowTitle(title);
    this->logic_status = new QLabel(this);
    this->logic_status->setText("Logic level: undefined");
    this->ui->statusBar->addWidget(logic_status, 1);
    this->resize(1280,720);

    this->scene = new QGraphicsScene(this);
    this->scene->setItemIndexMethod(QGraphicsScene::NoIndex);

    this->ui->graphicsView->setMinimumSize(500, 500);
    this->ui->graphicsView->setMaximumSize(1920, 1080);
    this->ui->graphicsView->setScene(scene);
    this->ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    this->ui->graphicsView->setCacheMode(QGraphicsView::CacheBackground);
    this->ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    this->scene->setSceneRect(QRect(0, 0, 1920, 1080));

    for (auto i = 0; i <= 1920; i += 40)
        this->scene->addLine(i, 0, i, 1080, QPen(Qt::darkGray));
    for (auto i = 0; i <= 1080; i += 40)
        this->scene->addLine(0, i, 1920, i, QPen(Qt::darkGray));

    this->ui->timeLabel->setText("Time: ");

    this->ui->tab->setEnabled(false);
    this->ui->pushButton->setEnabled(false);
    this->ui->addNet->setEnabled(false);
    this->ui->addInOut->setEnabled(false);
    this->ui->connector->setEnabled(false);
    this->enableUpdate(false);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::connectSlot(std::vector<id_t> ids)
{
    Net *net = new Net;
    net->Net_ID = findNID(all_nets);
    net->value = 0;
    net->start_addr.first = ids[0];
    net->end_addr.first = ids[1];
    net->showForm();
    this->scene->addItem(net);
    all_nets.push_back(net);
    if (all_nets.size() > 1)
        sort(all_nets.begin(), all_nets.end(), compNID);
    for (id_t i = 0; i < all_elements.size(); i++)
    {
        all_elements[i]->setOpacity(1);
        all_elements[i]->setScale(1);
    }
}

void MainWindow::delElSlot(id_t ID)
{
    qDebug() << "del";
    for (size_t i = 0; i < all_inOutputs.size(); i++)
        if (all_inOutputs[i]->addr.first == ID)
        {
            this->scene->removeItem(all_inOutputs[i]);
            all_inOutputs.erase(isIOIDExist(all_inOutputs[i]->IO_ID));
            i--;
        }
    for (size_t i = 0; i < all_nets.size(); i++)
        if (all_nets[i]->start_addr.first == ID || all_nets[i]->end_addr.first == ID)
        {
            this->scene->removeItem(all_nets[i]);
            all_nets.erase(isNIDExist(all_nets[i]->Net_ID));
            i--;
        }
    QObject::disconnect(*isLIDExist(ID), &LogicalElement::connectSignal, this, &MainWindow::connectSlot);
    QObject::disconnect(*isLIDExist(ID), &LogicalElement::delSignal, this, &MainWindow::delElSlot);
    this->scene->removeItem(*isLIDExist(ID));
    all_elements.erase(isLIDExist(ID));
    for (size_t i = 0; i < all_elements.size(); i++)
        all_elements[i]->update();
    if (all_elements.size() == 0)
    {
        this->ui->addNet->setEnabled(false);
        this->ui->addInOut->setEnabled(false);
        this->enableUpdate(false);
    }
}

void MainWindow::delIOSlot(id_t ID)
{
    QObject::disconnect(*isIOIDExist(ID), &Input_Output::delSignal, this, &MainWindow::delIOSlot);
    this->scene->removeItem(*isIOIDExist(ID));
    all_inOutputs.erase(isIOIDExist(ID));
}

void MainWindow::saveElById(id_t ID)
{
    el_index_to_save = returnLID(all_elements, ID);
    if (el_index_to_save > -1)
        saveToLib(lib_file, all_elements[el_index_to_save]);
    else
    {
        QMessageBox message;
        message.warning(this, "Warning", "No such element");
        message.show();
    }
    el_index_to_save = -1;
    lib_file = "";
}

void MainWindow::enableUpdate(bool _bool)
{
    this->ui->updateButton->setEnabled(_bool);
    this->ui->simulateButton->setEnabled(_bool);
    this->ui->plusTickerButton->setEnabled(_bool);
    this->ui->minusTickerButton->setEnabled(_bool);
    this->ui->tickerSlider->setEnabled(_bool);
    this->ui->timeLabel->setEnabled(_bool);
    this->ui->timeLineEdit->setEnabled(_bool);
    this->ui->timeLineEdit->setText("0");
}

void MainWindow::on_pushButton_clicked()
{
    LogicalElement *el = new LogicalElement;
    el->L_ID = findLID(all_elements);
    QObject::connect(el, &LogicalElement::connectSignal, this, &MainWindow::connectSlot);
    QObject::connect(el, &LogicalElement::delSignal, this, &MainWindow::delElSlot);
    all_elements.push_back(el);
    if (all_elements.size() > 1)
        sort(all_elements.begin(), all_elements.end(), compLID);
    el->setPos(randomBetween(30, 200), randomBetween(30, 200));
    this->scene->addItem(el);
    ui->addNet->setEnabled(true);
    ui->addInOut->setEnabled(true);
    this->enableUpdate(true);
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
    this->scene->addItem(net);
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
    this->ui->tab->setEnabled(true);
    if (logic_level == 2)
        ui->tab_1->setEnabled(true);
    else
        ui->tab_1->setEnabled(false);
    if (logic_level == 3)
        ui->tab_2->setEnabled(true);
    else
        ui->tab_2->setEnabled(false);
    this->ui->pushButton->setEnabled(true);
    this->ui->connector->setEnabled(true);
}

void MainWindow::on_notButton_clicked()
{
    LogicalElement *el = new LogicalElement;
    el->L_ID = findLID(all_elements);
    el->height = 60;
    el->width = 60;
    QObject::connect(el, &LogicalElement::connectSignal, this, &MainWindow::connectSlot);
    QObject::connect(el, &LogicalElement::delSignal, this, &MainWindow::delElSlot);
    all_elements.push_back(el);
    if (all_elements.size() > 1)
        sort(all_elements.begin(), all_elements.end(), compLID);
    el->setPos(randomBetween(30, 200), randomBetween(30, 200));
    this->scene->addItem(el);
    this->ui->addNet->setEnabled(true);
    this->ui->addInOut->setEnabled(true);
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
            for (unsigned column = 0; column < output_num; column++)
                el->T_outputs[row][column] = !row;
    }
    this->enableUpdate(true);
}


void MainWindow::on_andButton_clicked()
{
    LogicalElement *el = new LogicalElement;
    el->L_ID = findLID(all_elements);
    QObject::connect(el, &LogicalElement::connectSignal, this, &MainWindow::connectSlot);
    QObject::connect(el, &LogicalElement::delSignal, this, &MainWindow::delElSlot);
    all_elements.push_back(el);
    if (all_elements.size() > 1)
        sort(all_elements.begin(), all_elements.end(), compLID);
    el->setPos(randomBetween(30, 200), randomBetween(30, 200));
    this->scene->addItem(el);
    this->ui->addNet->setEnabled(true);
    this->ui->addInOut->setEnabled(true);
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
    qDebug() << all_elements.size();
    this->enableUpdate(true);
}


void MainWindow::on_orButton_clicked()
{
    LogicalElement *el = new LogicalElement;
    el->L_ID = findLID(all_elements);
    QObject::connect(el, &LogicalElement::connectSignal, this, &MainWindow::connectSlot);
    QObject::connect(el, &LogicalElement::delSignal, this, &MainWindow::delElSlot);
    all_elements.push_back(el);
    if (all_elements.size() > 1)
        sort(all_elements.begin(), all_elements.end(), compLID);
    el->setPos(randomBetween(30, 200), randomBetween(30, 200));
    this->scene->addItem(el);
    this->ui->addNet->setEnabled(true);
    this->ui->addInOut->setEnabled(true);
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
    this->enableUpdate(true);
}

void MainWindow::on_addInOut_clicked()
{
    Input_Output *io = new Input_Output;
    io->IO_ID = findIOID(all_inOutputs);
    QObject::connect(io, &Input_Output::delSignal, this, &MainWindow::delIOSlot);
    all_inOutputs.push_back(io);
    if (all_inOutputs.size() > 1)
        sort(all_inOutputs.begin(), all_inOutputs.end(), compIOID);
    io->setPos(randomBetween(30, 200), randomBetween(30, 200));
    this->scene->addItem(io);
    io->formIOP.show();
}

void MainWindow::on_connector_clicked()
{
    LogicalElement *el = new LogicalElement;
    el->L_ID = findLID(all_elements);
    el->is_connector = true;
    QObject::connect(el, &LogicalElement::connectSignal, this, &MainWindow::connectSlot);
    QObject::connect(el, &LogicalElement::delSignal, this, &MainWindow::delElSlot);
    all_elements.push_back(el);
    if (all_elements.size() > 1)
        sort(all_elements.begin(), all_elements.end(), compLID);
    el->setPos(randomBetween(30, 200), randomBetween(30, 200));
    this->scene->addItem(el);
    this->ui->addNet->setEnabled(true);
    this->ui->addInOut->setEnabled(true);
    vector<vector<value_t>> input_table = makeInputTable(el->L_inputs.size(), logic_level);
    el->T_outputs = input_table;
    el->update();
    this->enableUpdate(true);
}

void MainWindow::on_actionOpen_triggered()
{
    if (all_elements.size() > 0 || all_inOutputs.size() > 0 || all_nets.size() > 0)
    {
        QMessageBox box;
        box.warning(nullptr, "Warning", "Save your project, if you don't want to lose it");
        box.show();
    }
    current_file = QFileDialog::getOpenFileName(this, NULL, NULL, "LogiTect project (*.ltp);; All Files (*)");
    QString title;
    if (loadFile(current_file, this->scene, this) >= 0)
        title = "LogiTect | " + current_file;
    this->setWindowTitle(title);
}

void MainWindow::on_actionSave_triggered()
{
    if (all_elements.size() == 0 && all_inOutputs.size() == 0 && all_nets.size() == 0 && current_file == "")
    {
        QMessageBox box;
        box.information(nullptr, "Warning", "Nothing to save");
        box.show();
        return;
    }
    if (current_file == "")
        current_file = QFileDialog::getSaveFileName(this, NULL, NULL, "LogiTect project (*.ltp);; All Files (*)");
    saveFile(current_file);
    QString title = "LogiTect | " + current_file;
    this->setWindowTitle(title);
}

void MainWindow::on_actionSave_As_triggered()
{
    if (all_elements.size() == 0 && all_inOutputs.size() == 0 && all_nets.size() == 0)
    {
        QMessageBox box;
        box.information(nullptr, "Warning", "Nothing to save");
        box.show();
        return;
    }
    current_file = QFileDialog::getSaveFileName(this, NULL, NULL, "LogiTect project (*.ltp);; All Files (*)");
    saveFile(current_file);
    QString title = "LogiTect | " + current_file;
    this->setWindowTitle(title);
}

void MainWindow::on_updateButton_clicked()
{
    int iterations = updateScheme(MAX_ITERATIONS);
    if (iterations == -1)
    {
        QMessageBox message;
        message.critical(this, "Error", "Update timed out!");
        message.show();
    }
}

void MainWindow::on_simulateButton_clicked()
{
    simulateScheme(this);
}

void MainWindow::on_actionLoad_element_triggered()
{
    QString lib_file = QFileDialog::getOpenFileName(this, NULL, NULL, "LogiTect library (*.ltplib);; All Files (*)");
    LogicalElement *el = loadFromLib(lib_file);
    if (el == NULL)
    {
        qDebug() << "not loaded";
        return;
    }
    qDebug() << "loaded";
    el->L_ID = findLID(all_elements);
    QObject::connect(el, &LogicalElement::connectSignal, this, &MainWindow::connectSlot);
    QObject::connect(el, &LogicalElement::delSignal, this, &MainWindow::delElSlot);
    all_elements.push_back(el);
    if (all_elements.size() > 1)
        sort(all_elements.begin(), all_elements.end(), compLID);
    el->setPos(randomBetween(30, 200), randomBetween(30, 200));
    this->scene->addItem(el);
    this->ui->addNet->setEnabled(true);
    this->ui->addInOut->setEnabled(true);
    this->enableUpdate(true);
}

void MainWindow::on_actionSave_element_triggered()
{
    lib_file = QFileDialog::getSaveFileName(this, NULL, NULL, "LogiTect library (*.ltplib);; All Files (*)");
    if (inputs_ids.size() == 0 || outputs_ids.size() == 0)
    {
        this->form_ETS.show();
//        if (el_index_to_save > -1)
//            saveToLib(lib_file, all_elements[el_index_to_save]);
//        el_index_to_save = -1;
    }
    else
    {
        LogicalElement *el = convertToElement(inputs_ids, outputs_ids);
        saveToLib(lib_file, el);
        for (size_t i = 0; i < all_inOutputs.size(); i++)
        {
            all_inOutputs[i]->setOpacity(1);
            all_inOutputs[i]->setScale(1);
            all_inOutputs[i]->setCursor(QCursor(Qt::ArrowCursor));
        }
        inputs_ids.resize(0);
        outputs_ids.resize(0);
    }
}

void MainWindow::on_actionNew_project_triggered()
{
//    if (all_elements.size() > 0 || all_inOutputs.size() > 0 || all_nets.size() > 0)
//    {
//        QMessageBox box;
//        box.warning(nullptr, "Warning", "Save your project, if you don't want to lose it");
//        box.show();
//    }
    this->setWindowTitle("LogiTect");
    this->scene->clear();
    for (auto i = 0; i <= 1920; i += 40)
        this->scene->addLine(i, 0, i, 1080, QPen(Qt::darkGray));
    for (auto i = 0; i <= 1080; i += 40)
        this->scene->addLine(0, i, 1920, i, QPen(Qt::darkGray));
    all_elements.resize(0);
    all_nets.resize(0);
    all_inOutputs.resize(0);
    ticker = 0;
    current_file = "";
    this->ui->addNet->setEnabled(false);
    this->ui->addInOut->setEnabled(false);
    this->enableUpdate(false);
}

void MainWindow::on_plusTickerButton_clicked() {
    if ((int)ticker < this->ui->tickerSlider->maximum())
        ticker++;
    this->ui->timeLineEdit->setText(QString::number(ticker));
    this->ui->tickerSlider->setValue(ticker);
    useSimulation(ticker);
}
void MainWindow::on_minusTickerButton_clicked() {
    if ((int)ticker > this->ui->tickerSlider->minimum())
        ticker--;
    this->ui->timeLineEdit->setText(QString::number(ticker));
    this->ui->tickerSlider->setValue(ticker);
    useSimulation(ticker);
}
void MainWindow::on_tickerSlider_valueChanged(int value) {
    ticker = value;
    this->ui->timeLineEdit->setText(QString::number(ticker));
    useSimulation(ticker);
}
void MainWindow::on_timeLineEdit_textChanged(const QString &arg1) {
    ticker = arg1.toULongLong();
    this->ui->tickerSlider->setValue(ticker);
    useSimulation(ticker);
}
