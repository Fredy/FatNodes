#include "fatNode.hpp"

size_t FatNode::version = 0;

FatNode::FatNode() {
  this->left[this->version] = nullptr;
  this->right[this->version] = nullptr;
}

FatNode::FatNode(const int value) {
  this->value[this->version] = value;
  this->left[this->version] = nullptr;
  this->right[this->version] = nullptr;
}

FatNode *FatNode::inject(const int value, const Side side) {
  FatNode *tmp = new FatNode(value);
  if (side == Side::LEFT) {
    this->left[this->version] = tmp;
  } else {
    this->right[this->version] = tmp;
  }
  this->version++;
  return tmp;
}

void FatNode::eject(const Side side) {
  if (side == Side::LEFT) {
    this->left[this->version] = nullptr;
  } else {
    this->right[this->version] = nullptr;
  }
  this->version++;
}

void FatNode::change(const int value) {
  this->value[this->version] = value;
  this->version++;
}
