#include "net.h"
#include "logictypes.h"
#include "methods.h"
#include <stdlib.h>
#include "logicalelement.h"

extern std::vector<LogicalElement *> all_elements;

Net::Net(QObject *parent)
    : QObject{parent}, QGraphicsItem()
{
    QObject::connect(&this->form_NP, &Net_Properties::propSignal, this, &Net::propSlot);
    QObject::connect(this, &Net::connectSignal, &this->form_NP, &Net_Properties::addrChangedSlot);
    start_pos = QPoint(10, 10);
    end_pos = QPoint(100, 200);
    this->thickness = 2;
}

Net::~Net()
{

}

void Net::showForm()
{
    emit connectSignal(this->start_addr.first, this->end_addr.first);
    this->form_NP.show();
}

QRectF Net::boundingRect() const
{
    //return QRectF(this->start_pos.x(), this->start_pos.y(), this->end_pos.x(), this->end_pos.y());
    return QRectF(0, 0, 1920, 1080);
}

void Net::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    this->setPos(0, 0);
    painter->setPen(QPen(QBrush(Qt::black), this->thickness));
    QFont font = painter->font();
    font.setPixelSize(18);
    painter->setFont(font);
    QLineF line(this->start_pos, this->end_pos);
    painter->drawLine(line);
    painter->setBrush(Qt::white);
    qreal width_2 = 7;
    QPointF diag(width_2 * sqrt(2), width_2 * sqrt(2));
    QRectF rect(QPointF((this->start_pos + this->end_pos) / 2 - diag),  QPointF((this->start_pos + this->end_pos) / 2 + diag));
    painter->drawRect(rect);
    painter->drawText(rect, Qt::AlignCenter, QString::number(this->value));
    painter->drawEllipse(this->start_pos, 5, 5);
    painter->drawEllipse(this->end_pos, 5, 5);
}

//void Net::mousePressEvent(QGraphicsSceneMouseEvent *event)
//{
//    if (event->button() == Qt::RightButton)
//        form_NP.show();
//}

void Net::propSlot(std::pair<id_t, ionum_t> start_addr, std::pair<id_t, ionum_t> end_addr, delay_t delay)
{
    this->start_addr = start_addr;
    this->end_addr = end_addr;
    this->net_delay = delay;
    id_t id_start = returnLID(all_elements, start_addr.first), id_end = returnLID(all_elements, end_addr.first);
    this->start_pos = QPointF(all_elements[id_start]->pos()) + QPointF(all_elements[id_start]->width,
                                                                       -all_elements[id_start]->height / 2
                                                                           + (all_elements[id_start]->height / (all_elements[id_start]->L_outputs.size() + 1)) * (start_addr.second + 1));;
    this->end_pos = QPointF(all_elements[id_end]->pos()) + QPointF(-all_elements[id_end]->width,
                                                                   -all_elements[id_end]->height / 2
                                                                       + (all_elements[id_end]->height / (all_elements[id_end]->L_inputs.size() + 1)) * (end_addr.second + 1));;
    update();
    QObject::connect(all_elements[id_start], &LogicalElement::coordsSignal, this, &Net::coordsStartSlot);
    QObject::connect(all_elements[id_end], &LogicalElement::coordsSignal, this, &Net::coordsEndSlot);
}

void Net::coordsStartSlot(QPointF pos)
{
    id_t id = returnLID(all_elements, start_addr.first);
    this->start_pos = pos + QPointF(all_elements[id]->width,
                                    -all_elements[id]->height / 2
                                        + (all_elements[id]->height / (all_elements[id]->L_outputs.size() + 1)) * (start_addr.second + 1));
    //qDebug() << (all_elements[id]->height / (all_elements[id]->L_outputs.size() + 1));
    update();
}

void Net::coordsEndSlot(QPointF pos)
{
    id_t id = returnLID(all_elements, end_addr.first);
    this->end_pos = pos + QPointF(-all_elements[id]->width,
                                  -all_elements[id]->height / 2
                                      + (all_elements[id]->height / (all_elements[id]->L_inputs.size() + 1)) * (end_addr.second + 1));
    update();
}
