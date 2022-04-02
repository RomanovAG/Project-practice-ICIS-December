#ifndef NET_PROPERTIES_H
#define NET_PROPERTIES_H

#include <QWidget>
#include "logictypes.h"

namespace Ui {
class Net_Properties;
}

class Net_Properties : public QWidget
{
    Q_OBJECT

public:
    explicit Net_Properties(QWidget *parent = nullptr);
    ~Net_Properties();

signals:
    void propSignal(std::pair<id_t, ionum_t> start_addr, std::pair<id_t, ionum_t> end_addr, delay_t delay);

public slots:
    void addrChangedSlot(id_t start, id_t end);

private slots:
    void on_OK_clicked();

    void on_Cancel_clicked();

private:
    Ui::Net_Properties *ui;
};

#endif // NET_PROPERTIES_H
