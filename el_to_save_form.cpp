#include "el_to_save_form.h"
#include "ui_el_to_save_form.h"
#include "logicalelement.h"
using namespace std;

extern vector<LogicalElement *> all_elements;

el_to_save_form::el_to_save_form(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::el_to_save_form)
{
    this->ui->setupUi(this);
//    qDebug() << all_elements.size();
//    if (all_elements.size() > 0)
//    {
//        this->ui->spinBox->setMinimum(all_elements[0]->L_ID);
//        this->ui->spinBox->setMaximum(all_elements.back()->L_ID);
//    }
//    else
//    {
//        this->ui->spinBox->setEnabled(false);
//        this->ui->buttonBox->setEnabled(false);
//    }
}

el_to_save_form::~el_to_save_form() { delete ui; }


void el_to_save_form::on_buttonBox_accepted()
{
    emit box_value(this->ui->spinBox->value());
    this->close();
}

