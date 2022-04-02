#ifndef LOGICALELEMENT_H
#define LOGICALELEMENT_H

#include <QtWidgets>
#include "logical_element_properties.h"
#include "logictypes.h"

class LogicalElement : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit LogicalElement(QObject *parent = nullptr);
    ~LogicalElement();

signals:
    void connectSignal(std::vector<id_t> ids);
    void coordsSignal(QPointF pos);

private:

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

public slots:
    void propSlot(QString name, ionum_t inum, ionum_t onum, std::vector<std::vector<value_t>> output_table);

public:
    bool is_connector = false;
    qreal width;
    qreal height;
    Logical_Element_Properties form_LEP;
    id_t L_ID;
    QString L_name;
    delay_t L_delay;
    std::vector<value_t> L_inputs, L_outputs;
    //std::vector<Temp> temps;

    std::vector<std::vector<value_t>> T_outputs;
    std::vector<value_t> getOutput(level_t logic_level, std::vector<value_t> L_inputs);
};

#endif // LOGICALELEMENT_H
