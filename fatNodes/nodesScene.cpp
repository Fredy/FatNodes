#include "nodesScene.hpp"
#include "fatBinaryTree/fatBinaryTree.hpp"
#include "fatBinaryTree/fatNode.hpp"
#include "graphicNode.hpp"
#include <QDebug>
#include <vector>

NodesScene::NodesScene() {}

NodesScene::NodesScene(QObject *parent) : QGraphicsScene(parent) {
  this->tree = new FatBinaryTree();
}

void NodesScene::updateTree() {
  // First the scene is cleared.
  this->clear();
  qDebug() << "Tree:  "<< this->tree->currentVer << '\n';
  qDebug() << "NODES: " << FatNode::version << '\n';

  vector<FatNode *> nodesV;
  nodesV.push_back(this->tree->root());
  size_t size;

  double position = 0.0;
  double level = 0.0;
  int ilvl = 0;

  // TODO: save each level in a vector and calculate the number of levels.
  while (nodesV.size() != 0) {
    size = nodesV.size();
    position = -30.0 * ilvl * ilvl / 2;

    for (size_t i = 0; i < size; i++) {
      if (nodesV[i]) {
        // PRINT
        GraphicNode *tmpg =
            new GraphicNode(nodesV[i], QPointF(position, level));
        this->addItem(tmpg);
        position += 50.0;

        nodesV.push_back(nodesV[i]->getLeft(this->tree->currentVer));
        nodesV.push_back(nodesV[i]->getRight(this->tree->currentVer));
      } else {
        // PRINT WHITE SPACE
        position += 50.0;
      }
    }
    level += 50.0;
    ilvl++;
    nodesV.erase(nodesV.begin(), nodesV.begin() + size);
  }
}

void NodesScene::undoTree() {
  bool up = this->tree->undo();
  if (up)
    this->updateTree();
}

void NodesScene::redoTree() {
  bool up = this->tree->redo();
  if (up)
    this->updateTree();
}
void NodesScene::inserTree(int value) { this->tree->insert(value); }
