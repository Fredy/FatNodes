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
  this->ui->setupUi(this);

  this->scene = new NodesScene(this);
  this->ui->graphicsView->setScene(this->scene);

  this->scene->tree->insert(100);
  this->scene->tree->insert(80);
  this->scene->tree->insert(120);
  this->scene->tree->insert(50);
  this->scene->tree->insert(90);
  this->scene->tree->insert(110);
  this->scene->tree->insert(130);
  this->scene->tree->insert(30);
  this->scene->tree->insert(60);
  this->scene->tree->insert(91);
  this->scene->tree->insert(95);
  this->scene->tree->insert(93);
  this->scene->tree->insert(92);
  this->scene->updateTree();

  //  this->scene->tree->printBFS(100);
  //  this->scene->tree->pprint();
  //  this->scene->updateTree();

  connect(ui->btnRedo, SIGNAL(clicked()), scene, SLOT(redoTree()));
  connect(ui->btnUndo, SIGNAL(clicked()), scene, SLOT(undoTree()));
  connect(ui->btnInsert, SIGNAL(clicked()), this, SLOT(handleInsert()));
  connect(ui->btnRemove, SIGNAL(clicked()), this, SLOT(handleRemove()));
  connect(ui->lineEdit, SIGNAL(returnPressed()), this, SLOT(handleInsert()));

  // Changing the current version:
  connect(ui->btnRedo, SIGNAL(clicked()), this, SLOT(handleVersion()));
  connect(ui->btnUndo, SIGNAL(clicked()), this, SLOT(handleVersion()));
  connect(ui->btnInsert, SIGNAL(clicked()), this, SLOT(handleVersion()));
  connect(ui->btnRemove, SIGNAL(clicked()), this, SLOT(handleVersion()));
  connect(ui->lineEdit, SIGNAL(returnPressed()), this, SLOT(handleVersion()));
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::handleInsert() {
  int value = ui->lineEdit->text().toInt();
  this->scene->inserTree(value);

  this->ui->lineEdit->setText("");
  this->scene->updateTree();
}

void MainWindow::handleRemove() {
  int value = ui->lineEdit->text().toInt();
  this->scene->removeTree(value);

  this->ui->lineEdit->setText("");
  this->scene->updateTree();
}

void MainWindow::handlefind() {}

void MainWindow::handleVersion() {
  size_t version = this->scene->tree->currentVer;
  this->ui->lblVersion->setText(QString::number(version));
}
