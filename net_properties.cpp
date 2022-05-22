#include "net_properties.h"
#include "ui_net_properties.h"

Net_Properties::Net_Properties(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Net_Properties)
{
    this->ui->setupUi(this);
}

Net_Properties::~Net_Properties() { delete ui; }

void Net_Properties::addrChangedSlot(id_t start, id_t end)
{
    this->ui->startidtBox->setValue(start);
    this->ui->endidBox->setValue(end);
}

void Net_Properties::on_OK_clicked()
{
    std::pair<id_t, ionum_t> start_addr, end_addr;
    start_addr.first = this->ui->startidtBox->value();
    start_addr.second = this->ui->onumBox->value();
    end_addr.first = this->ui->endidBox->value();
    end_addr.second = this->ui->inumBox->value();
    delay_t delay = this->ui->delayBox->value();
    emit this->propSignal(start_addr, end_addr, delay);
    this->close();
}

void Net_Properties::on_Cancel_clicked() { this->close(); }
