#include "ItemType.h"
#include "BinaryTree.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char * argv[]){
  BinaryTree tree;
  ItemType item;
  bool found = false;
  int input;
  fstream fs;
  fs.open(argv[1], fstream::in);
  if(fs.is_open()){
    fs >> input;
    while(!fs.eof()){
      item.initialize(input);
      tree.insertItem(item);
      fs >> input;
    }
  }
  else{
    cout << "Failed to open the input file" << endl;
    return 0;
  }

  bool isRunning = true;
  int intInput;
  char charInput;

  while(isRunning){
    cout << endl;
    cout << "Commands: " << endl;
    cout << "insert (i), delete (d), retrieve(r), length (l), in-order (n), " << endl;
    cout << "pre-order (p), post-order (o), quit (q) " << endl;
    cout << "Enter a command: ";
    cin >> charInput;
    cin.clear(); fflush(stdin);
    if(charInput == 'p'){
      cout << "Pre-Order: "; tree.preOrder();
      cout << endl;
    }
    else if(charInput == 'n'){
      cout << "In-Order: "; tree.inOrder();
      cout << endl;
    }
    else if(charInput == 'o'){
      cout << "Post-Order: "; tree.postOrder();
      cout << endl;
    }
    else if(charInput == 'l'){
      cout << "List Length: " << tree.getLength() << endl;
    }
    else if(charInput == 'i'){
      cout << "Item to insert: ";
      cin >> intInput;
      cin.clear(); fflush(stdin);
      item.initialize(intInput);
      tree.insertItem(item);
      cout << "In-Order: "; tree.inOrder();
      cout << endl;
    }
    else if(charInput == 'd'){
      cout << "Item to delete: ";
      cin >> intInput;
      cin.clear(); fflush(stdin);
      item.initialize(intInput);
      tree.deleteItem(item);
      cout << "In-Order: "; tree.inOrder();
      cout << endl;
    }
    else if(charInput == 'r'){
      cout << "Item to be retrieved: ";
      cin >> intInput;
      cin.clear(); fflush(stdin);
      item.initialize(intInput);
      tree.retrieve(item, found);
      if(found){
        cout << "Item found in tree" << endl;
      }
      else{
        cout << "Item not in tree" << endl;
      }
    }
    else if(charInput == 'q'){
      isRunning = false;
    }
    else{
      cout << "Command not recognized. Try again" << endl;
    }
  }
}
