#include "graphicsscene.h"
#include "net.h"
#include "logictypes.h"
using namespace std;

extern vector<Net *> all_nets;

Cache::Cache(QObject *parent)
    : QObject{parent}, QGraphicsItem()
{
    this->setPos(0, 0);
}

Cache::~Cache()
{

}

QRectF Cache::boundingRect() const
{
    return QRectF(0, 0, 1920, 1080);
}

void Cache::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(painter);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

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

}

//void GraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
//{
//    qreal width_2 = 7;
//    QPointF diag(width_2 * sqrt(2), width_2 * sqrt(2));

//    for (unsigned i = 0; i < all_nets.size(); i++)
//    {
//        QPointF a((all_nets[i]->start_pos + all_nets[i]->end_pos) / 2 - diag);
//        QPointF b((all_nets[i]->start_pos + all_nets[i]->end_pos) / 2 + diag);
//        if (event->pos().x() >= a.x() && event->pos().y() >= a.y() && event->pos().x() <= b.x() && event->pos().y() <= b.y())
//        {
//            all_nets[i]->showForm();
//        }
//    }
//}
