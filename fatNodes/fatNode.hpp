#pragma once
#include <unordered_map>
#include <utility>
using namespace std;

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

  // The version value is the lattest version + 1
  static size_t version;

  FatNode();
  FatNode(const int value);

  // Returns a pointer to the insertet node
  FatNode *inject(const int value, const Side side);
  void eject(const Side side);
  void change(const int value);
};
