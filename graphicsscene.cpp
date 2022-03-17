#include "graphicsscene.h"

GraphicsScene::GraphicsScene(QObject *parent)
    : QGraphicsScene{parent}
{

}

void GraphicsScene::currentItem(LogicalElement *ptr)
{
    ctrl_on = true;
    current = ptr;
}

void GraphicsScene::keyPressEvent(QKeyEvent *event)
{
    Q_UNUSED(event);
    //QGraphicsScene::keyPressEvent(event);
    //if (event->key() == Qt::Key_Control)
        //qDebug() << "Success";
}
