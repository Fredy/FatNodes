#pragma once
#include <QGraphicsEllipseItem>

class FatNode;

class GraphicNode : public QGraphicsEllipseItem {
public:
  FatNode *data;

  GraphicNode(FatNode *data, const QPointF &center, const double radius = 20.0,
              QGraphicsItem *parent = nullptr);
};
