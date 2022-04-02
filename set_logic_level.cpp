#include "set_logic_level.h"
#include "ui_set_logic_level.h"
#include "logictypes.h"
#include "mainwindow.h"

Set_logic_level::Set_logic_level(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Set_logic_level)
{
    ui->setupUi(this);
    this->setWindowTitle("");
    ui->spinBox->setMinimum(2);
    ui->spinBox->setMaximum(255);
    this->setFixedSize(215, 91);
}

Set_logic_level::~Set_logic_level()
{
    delete ui;
}

void Set_logic_level::on_pushButton_clicked()
{
    level_t new_logic_level = ui->spinBox->value();
    emit logicLevelChanged(new_logic_level);
    this->close();
}

void Set_logic_level::on_cancel_clicked()
{
    this->close();
}

