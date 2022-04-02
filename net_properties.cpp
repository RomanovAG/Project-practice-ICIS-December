#include "net_properties.h"
#include "ui_net_properties.h"


Net_Properties::Net_Properties(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Net_Properties)
{
    ui->setupUi(this);
}

Net_Properties::~Net_Properties()
{
    delete ui;
}

void Net_Properties::addrChangedSlot(id_t start, id_t end)
{
    ui->startidtBox->setValue(start);
    ui->endidBox->setValue(end);
}

void Net_Properties::on_OK_clicked()
{
    std::pair<id_t, ionum_t> start_addr, end_addr;
    start_addr.first = ui->startidtBox->value();
    start_addr.second = ui->onumBox->value();
    end_addr.first = ui->endidBox->value();
    end_addr.second = ui->inumBox->value();
    delay_t delay = ui->delayBox->value();
    emit propSignal(start_addr, end_addr, delay);
    close();
}


void Net_Properties::on_Cancel_clicked()
{
    close();
}

