#include "input_output_properties.h"
#include "ui_input_output_properties.h"
#include "logictypes.h"

extern level_t logic_level;

Input_Output_Properties::Input_Output_Properties(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Input_Output_Properties)
{
    this->ui->setupUi(this);
    this->ui->inputBox->setMinimum(-1);
    this->ui->inputBox->setValue(-1);
    this->ui->outputBox->setMinimum(-1);
    this->ui->outputBox->setValue(-1);
    this->ui->valueBox->setMinimum(0);
    this->ui->valueBox->setMaximum(logic_level - 1);
}

Input_Output_Properties::~Input_Output_Properties() { delete this->ui; }

void Input_Output_Properties::on_buttonBox_accepted()
{
    bool is_input;
    ionum_t io_id = 0;
    if (this->ui->inputBox->isEnabled() == true)
    {
        is_input = true;
        io_id = this->ui->inputBox->value();
    }
    else
    {
        is_input = false;
        io_id = this->ui->outputBox->value();
    }
    emit valueChanged(this->ui->valueBox->value(), this->ui->IDBox->value(), io_id, is_input);
    this->close();
}


void Input_Output_Properties::on_inputBox_valueChanged(int arg1)
{
    if (arg1 >= 0)
        this->ui->outputBox->setEnabled(false);
    else
        this->ui->outputBox->setEnabled(true);
}


void Input_Output_Properties::on_outputBox_valueChanged(int arg1)
{
    if (arg1 >= 0)
        this->ui->inputBox->setEnabled(false);
    else
        this->ui->inputBox->setEnabled(true);
}


void Input_Output_Properties::on_buttonBox_rejected()
{
    this->close();
}

void Input_Output_Properties::on_delButton_clicked() { emit delSignal(); this->close(); }

