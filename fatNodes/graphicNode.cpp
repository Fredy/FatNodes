#include "graphicNode.hpp"
#include <QPen>

GraphicNode::GraphicNode(FatNode *data, const QPointF &center,
                         const double radius, QGraphicsItem *parent)
    : QGraphicsEllipseItem(center.x() - radius, center.y() - radius, radius * 2,
                           radius * 2, parent) {
  this->data = data;
  this->setPen(QPen(Qt::black, 1.0));
  // this->setBrush(Qt::red); // TODO: find a good color;
  this->setFlag(QGraphicsItem::ItemIsSelectable, true);
}
