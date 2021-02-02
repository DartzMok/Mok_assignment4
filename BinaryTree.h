#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "ItemType.h"
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

struct Node{
  ItemType key;
  Node *left;
  Node *right;
};

class BinaryTree{
 public:
  //Default Constructor
  BinaryTree();

  //Destructor
  ~BinaryTree();
  void postOrderDelete(Node*& node);

  //Inserts a non-duplicate item into the tree
  void insertItem(ItemType key);
  void Insert(Node*& node, ItemType key);

  //Deletes an item present in the tree
  void deleteItem(ItemType key);
  void Delete(Node*& node, ItemType key);
  void deleteNode(Node*& node, ItemType key);
  void findPredecessor(Node* node, ItemType& data);

  //Finds if an item is present in the tree
  void retrieve(ItemType &item, bool &found) const;

  //Prints the tree in preorder
  void preOrder() const;
  void preOrderPrint(Node *node) const;

  //Prints the tree in order
  void inOrder() const;
  void inOrderPrint(Node *node) const;

  //Prints the tree in postorder
  void postOrder() const;
  void postOrderPrint(Node *node) const;

  //Returns the length of the tree
  int getLength() const;

 private:
  Node *root;
  int length;
};
#endif
