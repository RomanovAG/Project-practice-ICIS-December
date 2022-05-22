#include "logical_element_properties.h"
#include "ui_logical_element_properties.h"
#include "methods.h"
#include <QDebug>
#include <QMessageBox>
#include <cmath>
using namespace std;
extern level_t logic_level;

Logical_Element_Properties::Logical_Element_Properties(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Logical_Element_Properties)
{
    this->ui->setupUi(this);
    this->setWindowTitle("Properties: logical element");
    this->ui->inputNumBox->setMinimum(1);
    this->ui->outputNumBox->setMinimum(1);
    this->ui->inputsTextEdit->setReadOnly(true);
}

Logical_Element_Properties::~Logical_Element_Properties() { delete this->ui; }

void Logical_Element_Properties::propSlot(QString name, ionum_t inum, ionum_t onum, std::vector<std::vector<value_t> > output_table, delay_t delay)
{
    this->ui->nameEdit->setText(name);
    this->ui->inputNumBox->setValue(inum);
    this->ui->outputNumBox->setValue(onum);
    this->ui->delayBox->setValue(delay);
    auto rows = (rows_t) pow(logic_level, inum);
    this->ui->outputsTextEdit->clear();
    for (unsigned row = 0; row < rows; row++)
    {
        for (auto column = 0; column < onum; column++)
        {
            this->ui->outputsTextEdit->insertPlainText(QString::number(output_table[row][column]));
            this->ui->outputsTextEdit->insertPlainText(" ");
        }
        this->ui->outputsTextEdit->insertPlainText("\n");
    }
}

void Logical_Element_Properties::on_OK_clicked()
{
    QString text = this->ui->outputsTextEdit->toPlainText();
    QRegExp delim(" \n?|\n");
    QStringList list = text.split(delim);
    qDebug() << text;
    qDebug() << list;
    auto input_num = this->ui->inputNumBox->value();
    auto output_num = this->ui->outputNumBox->value();
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
    emit this->propSignal(this->ui->nameEdit->text(),
                          this->ui->inputNumBox->value(),
                          this->ui->outputNumBox->value(),
                          output_table,
                          this->ui->delayBox->value());
    this->close();
}

void Logical_Element_Properties::on_Cancel_clicked()
{
    this->close();
}

void Logical_Element_Properties::on_inputNumBox_valueChanged(int arg1)
{

    this->ui->inputsTextEdit->clear();
    this->ui->outputsTextEdit->clear();
    auto input_num = arg1;
    auto output_num = this->ui->outputNumBox->value();
    auto rows = (rows_t) pow(logic_level, input_num);
//    vector<vector<value_t>> input_table (rows, vector<value_t> (input_num));

//    for (unsigned i = 0; i < rows; i++)
//    {
//        auto current_row = i;
//        for (int j = input_num - 1; j >= 0; j--)
//        {
//            input_table[i][j] = current_row % logic_level;
//            current_row /= logic_level;
//        }
//    }
    vector<vector<value_t>> input_table = makeInputTable(input_num, logic_level);
    for (unsigned row = 0; row < rows; row++)
    {
        for (auto column = 0; column < input_num; column++)
        {
            this->ui->inputsTextEdit->insertPlainText(QString::number(input_table[row][column]));
            this->ui->inputsTextEdit->insertPlainText(" ");
        }
        this->ui->inputsTextEdit->insertPlainText("\n");
    }
    for (unsigned row = 0; row < rows; row++)
    {
        for (auto column = 0; column < output_num; column++)
        {
            this->ui->outputsTextEdit->insertPlainText("0");
            this->ui->outputsTextEdit->insertPlainText(" ");
        }
        this->ui->outputsTextEdit->insertPlainText("\n");
    }
}


void Logical_Element_Properties::on_outputNumBox_valueChanged(int arg1)
{
    this->ui->outputsTextEdit->clear();
    auto input_num = this->ui->inputNumBox->value();
    auto output_num = arg1;
    auto rows = (rows_t) pow(logic_level, input_num);
    for (unsigned row = 0; row < rows; row++)
    {
        for (auto column = 0; column < output_num; column++)
        {
            this->ui->outputsTextEdit->insertPlainText("0");
            this->ui->outputsTextEdit->insertPlainText(" ");
        }
        this->ui->outputsTextEdit->insertPlainText("\n");
    }
}

void Logical_Element_Properties::on_delButton_clicked() { emit this->delSignal(); this->close(); }
