#include "fatBinaryTree.hpp"
#include "fatNode.hpp"
#include "types.hpp"

FatBinaryTree::FatBinaryTree() {
  this->root = nullptr;
  this->currentVer = 0;
}

FatNode **FatBinaryTree::find(int x) {
  FatNode **ptr = &this->root;

  while (*ptr and (*ptr)->value != x) {
    if (x > (*ptr)->value)
      ptr = &((*ptr)->getLeft(this->currentVer));
    else
      ptr = &((*ptr)->getRight(this->currentVer));
  }
  return ptr;
}

FatNode *FatBinaryTree::findParent(int x) {
  FatNode *ptr = &this->root;
  FatNode *ret;
  while (ptr and ptr->value != x) {
    ret = ptr;
    if (x > ptr->value)
      ptr = ptr->getLeft(this->currentVer);
    else
      ptr = ptr->getRight(this->currentVer);
  }
  return ret;
}

void FatBinaryTree::insert(int x) {
  FatNode *fnd = this->findParent(x);

  if (x > fnd->value) {
    if (!fnd->getLeft(this->currentVer))
      fnd->inject(x, Side::LEFT);
  } else {
    if (!fnd->getRight(this->currentVer))
      fnd->inject(x, Side::RIGHT);
  }

}

void FatBinaryTree::remove(int x);
