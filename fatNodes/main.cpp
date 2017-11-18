#include "mainWindow.hpp"
#include <QApplication>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  MainWindow w;
  w.show();

  return a.exec();
}

//#include <iostream>
//#include "fatBinaryTree.hpp"
// using namespace std;

// int main() {
//  FatBinaryTree tree;
//  tree.insert(3);
//  tree.insert(1);
//  tree.insert(2);
//  tree.insert(4);
//  tree.insert(5);
//  tree.insert(5);

//  tree.printBFS(0);
//  tree.printBFS(1);
//  tree.printBFS(2);
//  tree.printBFS(3);
//  tree.printBFS(4);
//  tree.printBFS(5);
//}
