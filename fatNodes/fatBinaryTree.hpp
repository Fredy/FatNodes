#pragma once
#include <vector>
using namespace std;

class FatNode;
class FatBinaryTree {
public:
  size_t currentVer;
  FatNode *root;

  FatBinaryTree();
  ~FatBinaryTree() = default;
  // To find the current version on nodes:
  // check for versions <= to the current version
  void redo();
  void undo();

  //--------------------
  // Binary tree methods
  //--------------------

  // Returns *nullptr (a pointer pointing to a nullptr) if it doesn't find the
  // element
  FatNode **find(int x);

  // Returns the previous element if it doesn't find the searched element
  FatNode *findParent(int x);
  void insert(int x);
  void remove(int x);

  // TODO: clear and destructor
};
