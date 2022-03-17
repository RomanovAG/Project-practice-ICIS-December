#include "logical_element_properties.h"
#include "ui_logical_element_properties.h"

Logical_Element_Properties::Logical_Element_Properties(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Logical_Element_Properties)
{
    ui->setupUi(this);
    setWindowTitle("Properties: logical element");
}

Logical_Element_Properties::~Logical_Element_Properties()
{
    delete ui;
}

void Logical_Element_Properties::on_OK_clicked()
{
    this->close();
}

void Logical_Element_Properties::on_Cancel_clicked()
{
    this->close();
}

