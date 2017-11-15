#pragma once

#include <QGraphicsScene>

class FatBinaryTree;
class NodesScene : public QGraphicsScene {
  Q_OBJECT
public:
  FatBinaryTree *tree;

public:
  NodesScene();
  NodesScene(QObject *parent);

  void updateTree();
public slots:
  void undoTree();
  void redoTree();
  void inserTree(int value);
};
