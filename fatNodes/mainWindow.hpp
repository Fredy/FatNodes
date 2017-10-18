#pragma once

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class QGraphicsScene;

class MainWindow : public QMainWindow {
  Q_OBJECT

private:
  Ui::MainWindow *ui;
  QGraphicsScene *scene;

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();
};
