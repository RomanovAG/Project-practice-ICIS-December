#ifndef NET_H
#define NET_H

#include <QtWidgets>
#include "logictypes.h"
#include "net_properties.h"
#include "temp.h"

class Net : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Net(QObject *parent = nullptr);
    ~Net();
    void showForm();

signals:
    void connectSignal(id_t start, id_t end);

public slots:
    void propSlot(std::pair<id_t, ionum_t> start_addr, std::pair<id_t, ionum_t> end_addr, delay_t delay);
    void coordsStartSlot(QPointF pos);
    void coordsEndSlot(QPointF pos);

private:
    int thickness;
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    //void mousePressEvent(QGraphicsSceneMouseEvent *event);

public:
    Net_Properties form_NP;
    QPointF start_pos, end_pos;
    id_t Net_ID;
    std::pair<id_t, ionum_t> start_addr, end_addr;
    delay_t net_delay;
    value_t value;

    std::vector<Temp> temps;
};

#endif // NET_H
