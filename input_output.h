#ifndef INPUT_OUTPUT_H
#define INPUT_OUTPUT_H

#include <QtWidgets>
#include "logictypes.h"
#include "input_output_properties.h"

class Input_Output : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Input_Output(QObject *parent = nullptr);
    ~Input_Output();

signals:
    void coordsSignal(QPointF pos);
    void delSignal(id_t ID);

public slots:
    void propSlot(value_t value, id_t ID, ionum_t io_id, bool is_input);
    void coordsSlot(QPointF pos);
    void delSlot();

private:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    //void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

public:
    qreal width;
    qreal height;
    id_t IO_ID;
    value_t value;
    std::pair<id_t, ionum_t> addr;
    bool is_input;
    Input_Output_Properties formIOP;
};

#endif // INPUT_OUTPUT_H
