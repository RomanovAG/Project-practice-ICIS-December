#include "input_output_properties.h"
#include "ui_input_output_properties.h"
#include "logictypes.h"

extern level_t logic_level;

Input_Output_Properties::Input_Output_Properties(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Input_Output_Properties)
{
    ui->setupUi(this);
    ui->inputBox->setMinimum(-1);
    ui->inputBox->setValue(-1);
    ui->outputBox->setMinimum(-1);
    ui->outputBox->setValue(-1);
    ui->valueBox->setMinimum(0);
    ui->valueBox->setMaximum(logic_level - 1);
}

Input_Output_Properties::~Input_Output_Properties()
{
    delete ui;
}

void Input_Output_Properties::on_buttonBox_accepted()
{
    bool is_input;
    ionum_t io_id = 0;
    if (ui->inputBox->isEnabled() == true)
    {
        is_input = true;
        io_id = ui->inputBox->value();
    }
    else
    {
        is_input = false;
        io_id = ui->outputBox->value();
    }
    emit valueChanged(ui->valueBox->value(), ui->IDBox->value(), io_id, is_input);
    //ui->inputBox->setEnabled(false);
    //ui->outputBox->setEnabled(false);
    this->close();
}


void Input_Output_Properties::on_inputBox_valueChanged(int arg1)
{
    if (arg1 >= 0)
    {
        ui->outputBox->setEnabled(false);
    }
    else
    {
        ui->outputBox->setEnabled(true);
    }
}


void Input_Output_Properties::on_outputBox_valueChanged(int arg1)
{
    if (arg1 >= 0)
    {
        ui->inputBox->setEnabled(false);
    }
    else
    {
        ui->inputBox->setEnabled(true);
    }
}


void Input_Output_Properties::on_buttonBox_rejected()
{
    this->close();
}

