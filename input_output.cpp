#include "input_output.h"
#include "logicalelement.h"
#include "methods.h"
using namespace std;

extern level_t logic_level;
extern vector<LogicalElement *> all_elements;
vector<id_t> inputs_ids, outputs_ids;

Input_Output::Input_Output(QObject *parent)
    : QObject{parent}
{
    this->width = 60;
    this->height = this->width / 2;
    this->value = 0;
    QObject::connect(&this->formIOP, &Input_Output_Properties::valueChanged, this, &Input_Output::propSlot);
    QObject::connect(&this->formIOP, &Input_Output_Properties::delSignal, this, &Input_Output::delSlot);
}

Input_Output::~Input_Output() {}

QRectF Input_Output::boundingRect() const
{
    return QRectF(-this->width / 2, -this->height / 2, this->width, this->height);
}

void Input_Output::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    QFont font = painter->font();
    font.setPixelSize(20);
    painter->setFont(font);
    painter->setPen(QPen(QBrush(Qt::black), 2));
    painter->setBrush(Qt::white);
    //painter->drawRect(-this->width / 2, -this->height / 2, this->width, this->height);
    painter->drawEllipse(QPointF(0, 0), this->width / 2, this->height / 2);
    painter->drawText(QRectF(-20, -10, 40, 20), Qt::AlignCenter, QString::number(this->value));
}

void Input_Output::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        this->setCursor(QCursor(Qt::ClosedHandCursor));
        this->setScale(1.1);
        if (event->modifiers() == Qt::ControlModifier)
            this->value = ++this->value % logic_level;
    }
    if (event->button() == Qt::RightButton)
        this->formIOP.show();
}

void Input_Output::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);
//    this->setPos(mapToScene(event->pos()));
//    emit coordsSignal(this->pos());
}

//void Input_Output::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
//{
//    Q_UNUSED(event);
//}

void Input_Output::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);
    if (event->modifiers() == Qt::ShiftModifier)
    {
        qDebug() << "shift";
        if (this->is_input == true)
            inputs_ids.push_back(this->IO_ID);
        else
            outputs_ids.push_back(this->IO_ID);
    }
    else
    {
        inputs_ids.resize(0);
        outputs_ids.resize(0);
        this->setOpacity(1);
        this->setScale(1);
        this->setCursor(QCursor(Qt::ArrowCursor));
    }
}

void Input_Output::propSlot(value_t value, id_t ID, ionum_t io_id, bool is_input)
{
    this->value = value;
    this->addr.first = ID;
    this->addr.second = io_id;
    this->is_input = is_input;
    QObject::connect(all_elements[ID], &LogicalElement::coordsSignal, this, &Input_Output::coordsSlot);
    if (this->is_input == false)
    {
        QPointF position = all_elements[ID]->pos() + QPointF(all_elements[ID]->width,
                                         -all_elements[ID]->height / 2
                                             + (all_elements[ID]->height / (all_elements[ID]->L_outputs.size() + 1)) * (addr.second + 1));
        this->setPos(position);
    }
    else
    {
        QPointF position = all_elements[ID]->pos() + QPointF(-all_elements[ID]->width,
                                         -all_elements[ID]->height / 2
                                             + (all_elements[ID]->height / (all_elements[ID]->L_inputs.size() + 1)) * (addr.second + 1));
        this->setPos(position);
    }
}

void Input_Output::coordsSlot(QPointF pos)
{
    id_t id = returnLID(all_elements, this->addr.first);
    if (this->is_input == false)
    {
        QPointF position = pos + QPointF(all_elements[id]->width,
                                                       -all_elements[id]->height / 2
                                                           + (all_elements[id]->height / (all_elements[id]->L_outputs.size() + 1)) * (addr.second + 1));
        this->setPos(position);
    }
    else
    {
        QPointF position = pos + QPointF(-all_elements[id]->width,
                                         -all_elements[id]->height / 2
                                             + (all_elements[id]->height / (all_elements[id]->L_inputs.size() + 1)) * (addr.second + 1));
        this->setPos(position);
    }
}

void Input_Output::delSlot() { emit delSignal(this->IO_ID); }
