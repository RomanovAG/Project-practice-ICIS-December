#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>
#include "logictypes.h"
#include <string>
#include "graphicsscene.h"

extern level_t logic_level;

static int randomBetween(int low, int high)
{
    return (QRandomGenerator::global()->generate() % ((high + 1) - low) + low);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
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
    scene->setSceneRect(QRect(QPoint(0, 0), QPoint(1920, 1080)));
    for (auto i = 0; i <= 1920; i += 40)
        scene->addLine(i, 0, i, 1080, QPen(Qt::darkGray));
    for (auto i = 0; i <= 1080; i += 40)
        scene->addLine(0, i, 1920, i, QPen(Qt::darkGray));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::wheelEvent(QWheelEvent *event)
{
    Q_UNUSED(event)
    //ui->graphicsView->scale(2, 2);
}

void MainWindow::on_pushButton_clicked()
{
    LogicalElement *item = new LogicalElement();
    item->setPos(randomBetween(30, 200), randomBetween(30, 200));
    scene->addItem(item);
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
}

void MainWindow::on_actionSet_logic_level_triggered()
{
    this->form_SLL.show();
}

void MainWindow::onLogicLevelChanged(level_t value)
{
    logic_level = value;
    this->logic_status->setText("Logic level: " + QString::number(logic_level));
}
