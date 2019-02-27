#include <iostream>
#include <cstring>
#include "node.h"

using namespace std;  

TreeNode* add(TreeNode* root, int num);
void print(TreeNode* root);


TreeNode* add(TreeNode* root, int num) {
  if (root == NULL) {

    root = new TreeNode(num);
    return root;
  }
  else if (root->getNumber() == num) {
    
  }
  else if (num < root->getNumber()) {

    if (root->getLeft() != NULL) {
    add(root->getLeft(), num);
    }
    else {

      TreeNode* newleft = new TreeNode(num);
      root->setLeft(newleft);
      return newleft;
    }
  }
  else if (num > root->getNumber()) {

    if (root->getRight() != NULL) {
    add(root->getRight(), num);
    }
    else {

      TreeNode* newright = new TreeNode(num);
      root->setRight(newright);
      return newright;
    }
  }
  
}



void print (TreeNode* root) {
  cout << root->getNumber() << endl;
  if (root->getLeft() != NULL) {

    print(root->getLeft());
  }
  if (root->getRight() != NULL) {

    print(root->getRight());
  }
 
}



int main() {
  TreeNode* root = NULL;
    cout << "How many numbers do you want to enter?" << endl;
  int numofnum = 0;
  cin >> numofnum;
  cout << "Enter your numbers" << endl;
  int counter = 0;
  int num = 0;
  while (counter != numofnum) {
    cin >> num;
    if (counter == 0) {
root = add(root, num);
  }
  else {
    add(root, num);
  }
  counter++;
  }
  print(root);
  return 0;
}
