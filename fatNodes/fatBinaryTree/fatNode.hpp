#pragma once
#include "types.hpp"
#include <utility>
using namespace std;

class FatNode {
private:
  // In a binary tree, the value of each node can't change.
  // But this in this implementation they can, if a value is changed
  // all the tree organization is broken, insert and find would not work.
  vmap<int> value;

  // Version, leftChild
  vmap<FatNode *> left;
  // Version, RightChild
  vmap<FatNode *> right;

public:
  // The version value is the lattest version + 1
  static size_t version;

  FatNode();
  FatNode(const int value);

  // Returns a pointer to the insertet node
  FatNode *inject(const int value, const Side side);
  void eject(const Side side);
  void change(const int value);

  FatNode *getLeft(const size_t version);
  FatNode *getRight(const size_t version);
  int getValue(const size_t version);
};
