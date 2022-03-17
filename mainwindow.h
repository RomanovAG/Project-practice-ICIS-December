#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "logicalelement.h"
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
    void paintEvent(QPaintEvent *event);
    void wheelEvent(QWheelEvent *event);

private slots:

    void on_pushButton_clicked();

    void on_actionSet_logic_level_triggered();

public slots:

    void onLogicLevelChanged(level_t value);

public:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    Set_logic_level form_SLL;
    //Logical_Element_Properties form_LEP;
};
#endif // MAINWINDOW_H
