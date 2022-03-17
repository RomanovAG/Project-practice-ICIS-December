#include "logicalelement.h"
#include "logictypes.h"

LogicalElement::LogicalElement(QObject *parent)
    : QObject{parent}, QGraphicsItem()
{
    this->width = 60;
    this->height = 120;
    this->L_inputs.resize(2);
    this->L_outputs.resize(3);
}

LogicalElement::~LogicalElement()
{

}

QRectF LogicalElement::boundingRect() const
{
    return QRectF (-this->width, -this->width, this->height, this->height);
}

void LogicalElement::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setPen(QPen(QBrush(Qt::black), 2));
    painter->setBrush(Qt::white);
    painter->drawRect(-this->width / 2, -this->height / 2, this->width, this->height);
painter->drawEllipse(-5, -5, 10, 10);
    for (int i = 0, pos = -this->height / 2 + this->height / (this->L_outputs.size() + 1); i < (int) this->L_outputs.size(); i++)
    {
        painter->drawLine(width / 2, pos, width , pos);
        pos += this->height / (this->L_outputs.size() + 1);
    }
    for (int i = 0, pos = -this->height / 2 + this->height / (this->L_inputs.size() + 1); i < (int) this->L_inputs.size(); i++)
    {
        painter->drawLine(-width / 2, pos, -width , pos);
        pos += this->height / (this->L_inputs.size() + 1);
    }
}

void LogicalElement::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    this->setPos(mapToScene(event->pos()));
}

void LogicalElement::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        if (event->modifiers() == Qt::ControlModifier)
        {
            qDebug() << "left with ctrl";
            L_inputs.resize(L_inputs.size() - 1);
        }
        this->setOpacity(0.5);
        this->setScale(1.1);
        this->setCursor(QCursor(Qt::ClosedHandCursor));
    }
    if (event->button() == Qt::RightButton)
        form_LEP.show();
    if (event->button() == Qt::MidButton)
        qDebug() << "mid";
    emit itemPtr(this);
}

void LogicalElement::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);
    //form_LEP.show();
    L_inputs.resize(L_inputs.size() + 1);
}

void LogicalElement::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);
    this->setOpacity(1);
    this->setScale(1);
    this->setCursor(QCursor(Qt::ArrowCursor));
}
