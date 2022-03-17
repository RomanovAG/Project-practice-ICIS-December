#ifndef GRAPHICSSCENE_H
#define GRAPHICSSCENE_H

#include <QGraphicsScene>
#include "logicalelement.h"

class GraphicsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit GraphicsScene(QObject *parent = nullptr);
    bool ctrl_on;
    LogicalElement *current;

protected:
    //void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

public slots:
    void currentItem(LogicalElement *ptr);

signals:

};

#endif // GRAPHICSSCENE_H
