#include "logicalelement.h"
#include "logictypes.h"
#include "temp.h"
using namespace std;

vector<id_t> el_to_connect;
extern level_t logic_level;

LogicalElement::LogicalElement(QObject *parent)
    : QObject{parent}, QGraphicsItem()
{
    QObject::connect(&this->form_LEP, &Logical_Element_Properties::propSignal, this, &LogicalElement::propSlot);
    QObject::connect(this, &LogicalElement::propSignal, &this->form_LEP, &Logical_Element_Properties::propSlot);
    QObject::connect(&this->form_LEP, &Logical_Element_Properties::delSignal, this, &LogicalElement::delSlot);
    this->width = 60;
    this->height = 120;
    this->L_inputs.resize(1);
    this->L_outputs.resize(1);
    vector<vector<value_t>> output_table ((rows_t) pow(logic_level, L_inputs.size()), vector<value_t> (L_outputs.size()));
    this->T_outputs = output_table;
    auto input_num = L_inputs.size();
    auto output_num = L_outputs.size();
    auto rows = (rows_t) pow(logic_level, input_num);
    for (rows_t row = 0; row < rows; row++)
        for (ionum_t column = 0; column < output_num; column++)
            T_outputs[row][column] = 0;

//    {
//        auto input_num = L_inputs.size();
//        auto output_num = L_outputs.size();
//        auto rows = (rows_t) pow(logic_level, input_num);
//        vector<vector<value_t>> input_table (rows, vector<value_t> (input_num));

//        for (unsigned i = 0; i < rows; i++)
//        {
//            auto current_row = i;
//            for (int j = input_num - 1; j >= 0; j--)
//            {
//                input_table[i][j] = current_row % logic_level;
//                current_row /= logic_level;
//            }
//        }
//        qDebug() << "Inputs ";
////        if (input_num > 6)
////        {
////            for (auto i = 0; i < input_num - 6; i++)
////                cout << " ";
////        }
////        cout << "Outputs" << endl;
//        for (unsigned row = 0; row < rows; row++)
//        {
//            for (unsigned column = 0; column < input_num; column++)
//            {
//                qDebug() << input_table[row][column] << " ";
//            }
//            for (unsigned n = 0; n < 5 - input_num; n++)
//            {
//                qDebug() << " ";
//            }
//            for (unsigned column = 0; column < output_num; column++)
//            {
//                qDebug() << (int) T_outputs[row][column] << " ";
//            }
////            qDebug() << "\n";
//        }
//    }
}

LogicalElement::~LogicalElement() {}

QRectF LogicalElement::boundingRect() const
{
    return QRectF(-this->width, -this->height / 2, this->width * 2, this->height);
}

void LogicalElement::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    QFont font = painter->font();
    font.setPixelSize(20);
    painter->setFont(font);
    painter->setPen(QPen(QBrush(Qt::black), 2));
    if (this->is_connector == true)
    {
        QRadialGradient gradient(0, 0, this->width);
        gradient.setColorAt(1, Qt::black);
        gradient.setColorAt(0, Qt::white);
        painter->setBrush(gradient);
        painter->drawRect(-this->width / 2, -this->height / 2 , this->width, this->height);
        painter->setPen(QPen(QBrush(Qt::white), 2));
        painter->drawText(QRectF(-this->width / 2 + 1, -this->height / 2 + 1, this->width, this->height),
                          Qt::AlignLeft, QString::number(this->L_ID));
        painter->setPen(QPen(QBrush(Qt::black), 2));
        for (int i = 0, pos = -this->height / 2 + this->height / (this->L_inputs.size() + 1); i < (int) this->L_inputs.size(); i++)
        {
            painter->drawLine(width, pos, -width , pos);
            pos += this->height / (this->L_inputs.size() + 1);
        }
    }
    else
    {
        painter->setBrush(Qt::white);
        painter->drawRect(-this->width / 2, -this->height / 2 , this->width, this->height);
        painter->drawText(QRectF(-this->width / 2, -this->height / 2, this->width, this->height),
                          Qt::AlignCenter, this->L_name);
        painter->drawText(QRectF(-this->width / 2 + 1, -this->height / 2 + 1, this->width, this->height),
                          Qt::AlignLeft, QString::number(this->L_ID));

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
}

void LogicalElement::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    this->setPos(mapToScene(event->pos()));
    emit coordsSignal(this->pos());
}

void LogicalElement::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        this->setCursor(QCursor(Qt::ClosedHandCursor));
        if (event->modifiers() == Qt::ControlModifier)
        {
            qDebug() << "ctrl + LMB";
            el_to_connect.push_back(this->L_ID);
            if (el_to_connect.size() == 2)
            {
                emit connectSignal(el_to_connect);
                el_to_connect.pop_back();
                el_to_connect.pop_back();
            }
            else
            {
                this->setOpacity(0.5);
                this->setScale(1.1);
            }
        }
        else
        {
            if (el_to_connect.size() > 0)
                el_to_connect.pop_back();
            this->setOpacity(0.5);
            this->setScale(1.1);
        }
    }
    if (event->button() == Qt::RightButton)
    {
        emit propSignal(this->L_name, this->L_inputs.size(), this->L_outputs.size(), this->T_outputs);
        form_LEP.show();
    }
    if (event->button() == Qt::MidButton)
        qDebug() << "mid";
}

void LogicalElement::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);
    emit propSignal(this->L_name, this->L_inputs.size(), this->L_outputs.size(), this->T_outputs);
    form_LEP.show();
}

void LogicalElement::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->modifiers() == Qt::ControlModifier)
    {
        qDebug() << "ctrl + release";
    }
    else
    {
        this->setOpacity(1);
        this->setScale(1);
    }
    this->setCursor(QCursor(Qt::ArrowCursor));
}

void LogicalElement::propSlot(QString name, ionum_t inum, ionum_t onum, std::vector<std::vector<value_t> > output_table)
{
    this->L_name = name;
    this->L_inputs.resize(inum);
    if (this->is_connector == true)
    {
        this->L_outputs.resize(this->L_inputs.size());
        auto rows = (rows_t) pow(logic_level, this->L_inputs.size());
        vector<vector<value_t>> input_table (rows, vector<value_t> (this->L_inputs.size()));
        for (unsigned i = 0; i < rows; i++)
        {
            auto current_row = i;
            for (int j = this->L_inputs.size() - 1; j >= 0; j--)
            {
                input_table[i][j] = current_row % logic_level;
                current_row /= logic_level;
            }
        }
        this->T_outputs = input_table;
    }
    else
    {
        this->L_outputs.resize(onum);
        this->T_outputs = output_table;
    }
}

void LogicalElement::delSlot() { emit delSignal(this->L_ID); }

vector<value_t> LogicalElement::getOutput(level_t logic_level, vector<value_t> L_inputs)
{
    rows_t row = 0;
    for (unsigned i = 0, j = L_inputs.size() - 1; i < L_inputs.size(); i++, j--)
        row += L_inputs[i] * (rows_t) pow(logic_level, j);
    //cout << "row: " << row << "\n";
    return this->T_outputs[row];
}
