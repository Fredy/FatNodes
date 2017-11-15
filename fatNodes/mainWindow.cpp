#include "mainWindow.hpp"
#include "fatBinaryTree.hpp"
#include "graphicNode.hpp"
#include "nodesScene.hpp"
#include "ui_mainWindow.h"
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QDebug>

#include "fatNode.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  this->scene = new NodesScene(this);
  ui->graphicsView->setScene(this->scene);

  this->scene->tree->insert(20);
  this->scene->tree->insert(10);
  this->scene->tree->insert(30);
  this->scene->tree->insert(5);
  this->scene->tree->insert(15);
  this->scene->tree->insert(25);
  this->scene->tree->insert(35);
  this->scene->tree->insert(3);
  this->scene->tree->insert(55);


  this->scene->tree->printBFS(100);
  this->scene->tree->pprint();
  this->scene->updateTree();


  connect(ui->btnRedo, SIGNAL(clicked()), scene, SLOT(redoTree()));
  connect(ui->btnUndo, SIGNAL(clicked()), scene, SLOT(undoTree()));
}

MainWindow::~MainWindow() { delete ui; }
