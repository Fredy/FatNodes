#include "graphicNode.hpp"
#include "fatBinaryTree/fatNode.hpp"
#include <QGraphicsTextItem>
#include <QFont>
#include <QPen>

GraphicNode::GraphicNode(FatNode *data, const QPointF &center,
                         const double radius, QGraphicsItem *parent)
    : QGraphicsEllipseItem(center.x() - radius, center.y() - radius, radius * 2,
                           radius * 2, parent) {
  this->data = data;
  this->setPen(QPen(Qt::black, 1.0));
  // this->setBrush(Qt::red); // TODO: find a good color;
  this->setFlag(QGraphicsItem::ItemIsSelectable, true);

  QGraphicsTextItem *text = new QGraphicsTextItem(QString::number(data->value),this);
  text->setFont(QFont("monospace", 14));
  text->setPos(this->rect().center() - QPointF(15.0, 15.0));
  //text->setPos();


  // GraphicNode *tmp = new GraphicNode(nullptr, QPointF(6.0,10.0));

  //auto ree = tmp->rect();
  //QGraphicsTextItem *algo = this->scene->addText("100", QFont("monospace", 14));

 // algo->setPos(ree.center() - QPointF(15.0, 15.0));


  //this->scene->addItem(tmp);
}
