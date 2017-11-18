#include "nodesScene.hpp"
#include "fatBinaryTree/fatBinaryTree.hpp"
#include "fatBinaryTree/fatNode.hpp"
#include "graphicNode.hpp"
#include <QDebug>
#include <QProcess>
#include <vector>

NodesScene::NodesScene() {}

NodesScene::NodesScene(QObject *parent) : QGraphicsScene(parent) {
  this->tree = new FatBinaryTree();
}

void NodesScene::updateTree() {
  // First the scene is cleared.
  this->clear();

  // We are using Graphviz to generate the graphic tree.
  QProcess *proc = new QProcess();
  string out = this->tree->printGraphviz(this->tree->currentVer);

  proc->setProcessChannelMode(QProcess::MergedChannels);
  proc->start("dot", QStringList() << "-Tpng");
  proc->write(out.c_str());

  QByteArray data;
  QPixmap pixmap = QPixmap();

  while (proc->waitForReadyRead(100)) {
    data.append(proc->readAll());
  }

  pixmap.loadFromData(data);
  this->addPixmap(pixmap);
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
