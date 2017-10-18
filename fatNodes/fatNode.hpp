#pragma once
#include <unordered_map>
#include <utility>

enum class Side {
  LEFT,
  RIGHT,
};

class FatNode {
public:
  // Version, value(int)
  unordered_map<size_t, int> value;
  // Version, leftChild
  unordered_map<size_t, FatNode *> left;
  // Version, RightChild
  unordered_map<size_t, FatNode *> right;

  void eject(Side side);
  // TODO: find all the operations receive the version numbers
  // this number comes from the containging tree.

  FatNode();
};
