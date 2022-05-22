#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QtWidgets>

#include "logical_element_properties.h"
#include "set_logic_level.h"
#include "el_to_save_form.h"
#include "logictypes.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton_clicked();

    void on_actionSet_logic_level_triggered();

    void on_addNet_clicked();

    void on_notButton_clicked();

    void on_andButton_clicked();

    void on_orButton_clicked();

    void on_addInOut_clicked();

    void on_connector_clicked();

    void on_actionOpen_triggered();

    void on_updateButton_clicked();
    void on_simulateButton_clicked();

    void on_actionSave_triggered();

    void on_actionSave_element_triggered();

    void on_actionSave_As_triggered();

    void on_actionNew_project_triggered();

    void on_actionLoad_element_triggered();

    void on_plusTickerButton_clicked();

    void on_minusTickerButton_clicked();

    void on_tickerSlider_valueChanged(int value);

    void on_timeLineEdit_textChanged(const QString &arg1);

public slots:
    void onLogicLevelChanged(level_t value);
    void connectSlot(std::vector<id_t> ids);
    void delElSlot(id_t ID);
    void delIOSlot(id_t ID);
    void saveElById(id_t ID);

public:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QLabel *logic_status;
    Set_logic_level form_SLL;
    el_to_save_form form_ETS;
    void enableUpdate(bool _bool);
};
#endif // MAINWINDOW_H
