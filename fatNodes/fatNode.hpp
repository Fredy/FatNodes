#pragma once
#include "types.hpp"
#include <utility>
using namespace std;

class FatNode {
public:
  // Version, value(int)
  // unordered_map<size_t, int> value;

  // In a binary tree, the value of each node can't change.
  int value;

  // Version, leftChild
  vmap<FatNode *> left;
  // Version, RightChild
  vmap<FatNode *> right;

  // The version value is the lattest version + 1
  static size_t version;

  FatNode();
  FatNode(const int value);

  // Returns a pointer to the insertet node
  FatNode *inject(const int value, const Side side);
  void eject(const Side side);
  // void change(const int value);

  FatNode *getLeft(const size_t version);
  FatNode *getRight(const size_t version);
};
