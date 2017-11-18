#include "mainWindow.hpp"
#include "fatBinaryTree/fatBinaryTree.hpp"
#include "graphicNode.hpp"
#include "nodesScene.hpp"
#include "ui_mainWindow.h"
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsTextItem>

#include "fatBinaryTree/fatNode.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  this->scene = new NodesScene(this);
  ui->graphicsView->setScene(this->scene);

  //  this->scene->tree->insert(20);
  //  this->scene->tree->insert(10);
  //  this->scene->tree->insert(30);
  //  this->scene->tree->insert(5);
  //  this->scene->tree->insert(15);
  //  this->scene->tree->insert(25);
  //  this->scene->tree->insert(35);
  //  this->scene->tree->insert(3);
  //  this->scene->tree->insert(55);

  this->scene->tree->printBFS(100);
  this->scene->tree->pprint();
  this->scene->updateTree();

  connect(ui->btnRedo, SIGNAL(clicked()), scene, SLOT(redoTree()));
  connect(ui->btnUndo, SIGNAL(clicked()), scene, SLOT(undoTree()));
  connect(ui->btnInsert, SIGNAL(clicked()), this, SLOT(handleInsert()));
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::handleInsert() {
  int value = ui->lineEdit->text().toInt();
  this->scene->inserTree(value);

  ui->lineEdit->setText("");
  this->scene->updateTree();
}

void MainWindow::handleRemove() {}

void MainWindow::handlefind() {}
