#include "fatBinaryTree.hpp"
#include "fatNode.hpp"
#include "types.hpp"
#include <iostream>
#include <limits>
#include <queue>

FatBinaryTree::FatBinaryTree() {
  this->mainPtr = new FatNode(numeric_limits<int>::max());
  this->currentVer = 0;
  this->maxVer = 0;
  FatNode::version++;
}

FatNode *FatBinaryTree::root(const size_t version) {
  return mainPtr->getLeft(version);
}

FatNode *FatBinaryTree::root() { return mainPtr->getLeft(this->currentVer); }

FatNode **FatBinaryTree::find(int x) {
  //  FatNode **ptr = &this->root;

  //  while (*ptr and (*ptr)->value != x) {
  //    if (x > (*ptr)->value)
  //      ptr = &((*ptr)->getLeft(this->currentVer));
  //    else
  //      ptr = &((*ptr)->getRight(this->currentVer));
  //  }
  //  return ptr;
}

FatNode *FatBinaryTree::findParent(int x) {
  FatNode *ptr = this->root(this->currentVer);
  FatNode *ret = this->mainPtr;
  while (ptr and ptr->value != x) {
    ret = ptr;
    if (x < ptr->value)
      ptr = ptr->getLeft(this->currentVer);
    else
      ptr = ptr->getRight(this->currentVer);
  }
  return ret;
}

void FatBinaryTree::insert(int x) {
  FatNode *fnd = this->findParent(x);
  bool inserted = false;

  // Find the correct position
  if (x < fnd->value) {
    if (!fnd->getLeft(this->currentVer)) {
      fnd->inject(x, Side::LEFT);
      inserted = true;
    }
  } else {
    if (!fnd->getRight(this->currentVer)) {
      fnd->inject(x, Side::RIGHT);
      inserted = true;
    }
  }

  if (inserted) {
    this->currentVer++;
    this->maxVer++;
  }
}

void FatBinaryTree::remove(int x) {
  /*
  FatNode *parent = this->findParent(x);
  FatNode *child;
  Side side;

  if (x < parent->value) {
    child = parent->getLeft(this->currentVer);
    if (!child)
      return;
  } else {
    child = parent->getRight(this->currentVer);
    if (!child)
      return;
  }

  if (child->getLeft(this->currentVer) and child->getRight(this->currentVer)) {
    // TODO: choose a random subtree.
    FatNode *tmp = child;
    tmp =  tmp->getLeft(this->currentVer);
    while (tmp->getRight(this->currentVer))
      tmp = tmp->getRight(this->currentVer);
    child = xd;
  }
  FatNode *tmp = child;
  */
}
/*
template<typename T>
bool ArbolBin<T>::remove(T x){
    Node<T> **ptr;
    if(!find(x,ptr)) return 0;
    if((*ptr)->nodes[0] and (*ptr)->nodes[1]){
        srand(time(NULL));
        bool random  = rand()%2;
        -----------
        Node<T> *tmp = *ptr;
        tmp = tmp->nodes[random];
        while(tmp->nodes[!random])
            tmp = tmp->nodes[!random];
        (*ptr)->val = tmp->val;
        -----------
    }
    Node<T> *tmp = *ptr;
    *ptr = (*ptr)->nodes[(*ptr)->nodes[1] != nullptr];
    delete tmp;
    return 1;
}
*/
void FatBinaryTree::printBFS(const size_t version) {
  queue<FatNode *> nodeq;
  nodeq.push(this->root(version));
  while (!nodeq.empty()) {
    if (nodeq.front()) {
      cout << nodeq.front()->value << ' ';
      nodeq.push(nodeq.front()->getLeft(version));
      nodeq.push(nodeq.front()->getRight(version));
    }
    nodeq.pop();
  }
  cout << "\n";
}

void FatBinaryTree::pprint() {
  vector<FatNode *> nodesV;
  nodesV.push_back(this->root());
  size_t size;

  while (nodesV.size() != 0) {
    size = nodesV.size();
    for (size_t i = 0; i < size; i++) {
      if (nodesV[i]) {
        cout << nodesV[i]->value << ' ';
        nodesV.push_back(nodesV[i]->getLeft(this->currentVer));
        nodesV.push_back(nodesV[i]->getRight(this->currentVer));
      } else {
        cout << ". ";
      }
    }
    cout << '\n';
    nodesV.erase(nodesV.begin(), nodesV.begin() + size);
  }
}

bool FatBinaryTree::redo() {
  if (this->currentVer < this->maxVer) {
    currentVer++;
    return true;
  }
  return false;
}

bool FatBinaryTree::undo() {
  if (this->currentVer > 0) {
    currentVer--;
    return true;
  }
  return false;
}
