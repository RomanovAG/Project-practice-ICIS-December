#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QtWidgets>
//#include "logicalelement.h"
#include "logical_element_properties.h"
#include "set_logic_level.h"
#include "logictypes.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QLabel *logic_status;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton_clicked();

    void on_actionSet_logic_level_triggered();

    void on_addNet_clicked();

    void on_pushButton_2_clicked();

    void on_notButton_clicked();

    void on_andButton_clicked();

    void on_orButton_clicked();

    void on_addInOut_clicked();

    void on_connector_clicked();

public slots:

    void onLogicLevelChanged(level_t value);

    void connectSlot(std::vector<id_t> ids);

public:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    Set_logic_level form_SLL;
};
#endif // MAINWINDOW_H
