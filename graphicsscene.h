#ifndef GRAPHICSSCENE_H
#define GRAPHICSSCENE_H

#include <QtWidgets>
#include "logicalelement.h"

class GraphicsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit GraphicsScene(QObject *parent = nullptr);
    bool ctrl_on;
    LogicalElement *current;

protected:
    void keyPressEvent(QKeyEvent *event) override;
    //void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

public slots:
    void currentItem(LogicalElement *ptr);

signals:

};

class Cache : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Cache(QObject *parent = nullptr);
    ~Cache();

private:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // GRAPHICSSCENE_H
