#include "mainWindow.hpp"
#include "ui_mainWindow.h"
#include <QGraphicsScene>
#include "graphicNode.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  this->scene = new QGraphicsScene(this);
  ui->graphicsView->setScene(this->scene);

  GraphicNode *tmp = new GraphicNode(nullptr, QPointF(0.0,0.0));
  this->scene->addItem(tmp);


}

MainWindow::~MainWindow() { delete ui; }
