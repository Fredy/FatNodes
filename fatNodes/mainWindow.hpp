#pragma once

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class NodesScene;

class MainWindow : public QMainWindow {
  Q_OBJECT

private:
  Ui::MainWindow *ui;
  NodesScene *scene;

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();
};
