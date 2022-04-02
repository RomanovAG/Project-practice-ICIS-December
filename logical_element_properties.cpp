#include "logical_element_properties.h"
#include "ui_logical_element_properties.h"
#include <QTextCodec>
#include <QDebug>
#include <QMessageBox>
#include <vector>
#include <cmath>
using namespace std;
extern level_t logic_level;

Logical_Element_Properties::Logical_Element_Properties(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Logical_Element_Properties)
{
    ui->setupUi(this);
    setWindowTitle("Properties: logical element");
    ui->inputNumBox->setMinimum(1);
    ui->outputNumBox->setMinimum(1);
    ui->inputsTextEdit->setReadOnly(true);
}

Logical_Element_Properties::~Logical_Element_Properties()
{
    delete ui;
}

void Logical_Element_Properties::on_OK_clicked()
{
    QString text = ui->outputsTextEdit->toPlainText();
    QRegExp delim(" \n?|\n");
    QStringList list = text.split(delim);
    qDebug() << text;
    qDebug() << list;
    auto input_num = ui->inputNumBox->value();
    auto output_num = ui->outputNumBox->value();
    auto rows = (rows_t) pow(logic_level, input_num);
    vector<vector<value_t>> output_table ((rows_t) pow(logic_level, input_num), vector<value_t> (output_num));
    unsigned long i = 0;
    QRegExp re("\\d*");  // a digit (\d), zero or more times (*)
    for (unsigned row = 0; row < rows; row++)
    {
        for (auto column = 0; column < output_num; column++)
        {

            if (re.exactMatch(list.at(i)) == false)
            {
                QMessageBox message;
                message.critical(this, "Error", "Invalud output table");
                message.show();
                return;
            }
            output_table[row][column] = list.at(i).toInt();
            i++;
        }
    }
    emit propSignal(ui->nameEdit->text(), ui->inputNumBox->value(), ui->outputNumBox->value(), output_table);
    this->close();
}

void Logical_Element_Properties::on_Cancel_clicked()
{
    this->close();
}

void Logical_Element_Properties::on_inputNumBox_valueChanged(int arg1)
{

    ui->inputsTextEdit->clear();
    ui->outputsTextEdit->clear();
    auto input_num = arg1;
    auto output_num = ui->outputNumBox->value();
    auto rows = (rows_t) pow(logic_level, input_num);
    vector<vector<value_t>> input_table (rows, vector<value_t> (input_num));

    for (unsigned i = 0; i < rows; i++)
    {
        auto current_row = i;
        for (int j = input_num - 1; j >= 0; j--)
        {
            input_table[i][j] = current_row % logic_level;
            current_row /= logic_level;
        }
    }

    for (unsigned row = 0; row < rows; row++)
    {
        for (auto column = 0; column < input_num; column++)
        {
            ui->inputsTextEdit->insertPlainText(QString::number(input_table[row][column]));
            ui->inputsTextEdit->insertPlainText(" ");
        }
        ui->inputsTextEdit->insertPlainText("\n");
    }
    for (unsigned row = 0; row < rows; row++)
    {
        for (auto column = 0; column < output_num; column++)
        {
            //ui->outputsTextEdit->insertPlainText("\u25a0");
            ui->outputsTextEdit->insertPlainText("0");
            ui->outputsTextEdit->insertPlainText(" ");
        }
        ui->outputsTextEdit->insertPlainText("\n");
    }
    //delete ui->gridLayout_2;
//    vector<QLayout *> *layout_table = new vector<QLayout *>(ui->outputNumBox->value());
//    rows_t rows = (rows_t) pow(logic_level, arg1);
//    vector<vector<QSpinBox *>> *output_table =
//        new vector<vector<QSpinBox *>>(rows, vector<QSpinBox *> (ui->outputNumBox->value()));
//    for (rows_t i = 0; i < rows; i++)
//    {
//        for (ionum_t j = 0; j < arg1; j++)
//        {
//            layout_table->at(i)->addWidget(output_table->at(i).at(j));
//        }
//        ui->gridLayout_2->addLayout(layout_table->at(i), i, 0);
//    }
}


void Logical_Element_Properties::on_outputNumBox_valueChanged(int arg1)
{
    ui->outputsTextEdit->clear();
    auto input_num = ui->inputNumBox->value();
    auto output_num = arg1;
    auto rows = (rows_t) pow(logic_level, input_num);
    for (unsigned row = 0; row < rows; row++)
    {
        for (auto column = 0; column < output_num; column++)
        {
            ui->outputsTextEdit->insertPlainText("0");
            ui->outputsTextEdit->insertPlainText(" ");
        }
        ui->outputsTextEdit->insertPlainText("\n");
    }
}

