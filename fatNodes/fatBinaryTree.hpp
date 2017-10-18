#pragma once
#include <vector>
using namespace std;

class FatBinaryTree {
public:
  size_t currentVer;

  FatBinaryTree();
  // To find the current version on nodes:
  // check for versions <= to the current version
  void redo();
  void undo();
};
