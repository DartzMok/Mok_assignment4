#include "BinaryTree.h"
#include "ItemType.h"
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

BinaryTree::BinaryTree(){
  root = NULL;
  length = 0;
}

int BinaryTree::getLength() const{
  return length;
}

void BinaryTree::postOrder() const{
  postOrderPrint(root);
}

void BinaryTree::postOrderPrint(Node *node) const{
  if(node != NULL){
    postOrderPrint(node -> left);
    postOrderPrint(node -> right);
    cout << node -> key.getValue() << " ";
  }
}

void BinaryTree::inOrder() const{
  inOrderPrint(root);
}

void BinaryTree::inOrderPrint(Node *node) const{
  if(node != NULL){
    inOrderPrint(node -> left);
    cout << node -> key.getValue() << " ";
    inOrderPrint(node -> right);
  }
}

void BinaryTree::preOrder() const{
  preOrderPrint(root);
}

void BinaryTree::preOrderPrint(Node *node) const{
  if(node != NULL){
    cout << node -> key.getValue() << " ";
    preOrderPrint(node -> left);
    preOrderPrint(node -> right);
  }
}

void BinaryTree::retrieve(ItemType &item, bool &found) const{
  Node *temp = root;
  found = false;
  //Node *preTemp = NULL;

  while(temp != NULL && found == false){
    if(item.compareTo(temp -> key) == LESS){
      //preTemp = temp;
      temp = temp ->left;
    }
    else if(item.compareTo(temp -> key) == GREATER){
      //preTemp = temp;
      temp = temp -> right;
    }
    else{
      found = true;
    }
  }
}
     
void BinaryTree::deleteItem(ItemType key){
  Delete(root, key);
}

void BinaryTree::Delete(Node*& node, ItemType key){
  if(node == NULL){
    cout << "Item is not in the tree" << endl;
  }
  else if(key.compareTo(node -> key) == LESS){
    Delete(node -> left, key);
  }
  else if(key.compareTo(node -> key) == GREATER){
    Delete(node -> right, key);
  }
  else if(key.compareTo(node -> key) == EQUAL){
    deleteNode(node, key);
  }
}

void BinaryTree::deleteNode(Node*& node, ItemType key){
  ItemType data;
  Node *temp = node;
  if(node -> left == NULL){
    node = node -> right;
    length--;
    delete temp;
  }
  else if(node -> right == NULL){
    node = node -> left;
    length--;
    delete temp;
  }
  else{
    findPredecessor(node -> left, data);
    node -> key = data;
    Delete(node -> left, data);
  }
}

void BinaryTree::findPredecessor(Node* node, ItemType& data){
  while(node -> right != NULL){
    node = node -> right;
  }
  data = node -> key;
}

void BinaryTree::Insert(Node*& node, ItemType key){
  if(node == NULL){
    Node *insert = new Node;
    insert -> right = NULL;
    insert -> left = NULL;
    insert -> key = key;
    node = insert;
    length++;
  }
  else if(key.compareTo(node -> key) == LESS){
    Insert(node -> left, key);   
  }
  else if(key.compareTo(node -> key) == GREATER){
    Insert(node -> right, key);
  }
  else{
    cout << "Item already exist in the tree" << endl;
  }
}

void BinaryTree::insertItem(ItemType key){
  Insert(root, key);
}

void BinaryTree::postOrderDelete(Node*& node){
  if(node != NULL){
    postOrderDelete(node -> left);
    postOrderDelete(node -> right);
    delete node;
  }
}

BinaryTree::~BinaryTree(){
  if(length > 0){
    postOrderDelete(root);
  }
}
