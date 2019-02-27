#include <iostream>
#include <cstring>
#include "node.h"

using namespace std;  

TreeNode* add(TreeNode* root, int num);
void print(TreeNode* root);
TreeNode* remove(TreeNode* realroot, TreeNode* root, TreeNode* parent, int num, int lr);


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
  cout << "Tree: " << endl;
  if (root != NULL) {
  cout << root->getNumber() << endl;
  if (root->getLeft() != NULL) {

    print(root->getLeft());
  }
  if (root->getRight() != NULL) {

    print(root->getRight());
  }
  }
 
}


TreeNode* remove (TreeNode* realroot, TreeNode* root, TreeNode* parent, int num, int lr) {
  bool done = false;
  if (root->getNumber() == num) {
    if (root->getLeft() == NULL && root->getRight() == NULL) {
      if (lr == 1) {
	cout << "Case 1" << endl;
	parent->setLeft(NULL);
	delete root;
	done = true;
	return realroot;
      }
       if (lr == 2) {
	cout << "Case 2" << endl;
	parent->setRight(NULL);
	delete root;
	done = true;
	return realroot;
      }
      if (lr == 0) {
	cout << "Case 3" << endl;
	delete root;
	done = true;
	return NULL;
      }
    }
    
    if (root->getLeft() == NULL && root->getRight() != NULL) {
      	if (lr == 1) {
	  cout << "Case 4" << endl;
	parent->setLeft(root->getRight());
	done = true;
	return realroot;
	}
	 if (lr == 2) {
	  cout << "Case 5" << endl;
	  parent->setRight(root->getRight());
	  done = true;
	  return realroot;
	}
	 if (lr == 0) {
	  cout << "Case 6" << endl;
	root = root->getRight();
	done = true;
	return root;
	}
    }
     if (root->getRight() == NULL && root->getLeft() != NULL) {
      	if (lr == 1) {
	  cout << "Case 7" << endl;
	parent->setLeft(root->getLeft());
	done = true;
	return realroot;
	}
	 if (lr == 2) {
	  cout << "Case 8" << endl;
	  parent->setRight(root->getLeft());
	  done = true;
	  return realroot;
	}
	 if (lr == 0) {
	  cout << "Case 9" << endl;
	root = root->getLeft();
	done = true;
	return root;
	}
    }
    if (root->getLeft() != NULL && root->getRight() != NULL) {
      if (lr == 1) {
	cout << "Case 10" << endl;
      TreeNode* moverright = root->getRight();
      while (moverright->getLeft() != NULL) {
	moverright = moverright->getLeft();
      }
      parent->setLeft(root->getRight());
      moverright->setLeft(root->getLeft());
      delete root;
      done = true;
      return realroot;
      }
      if (lr == 2) {
	cout << "Case 11" << endl;
	TreeNode* moverleft = root->getLeft();
	while (moverleft->getRight() != NULL) {
	  moverleft = moverleft->getRight();
	}
	parent->setRight(root->getLeft());
	moverleft->setRight(root->getRight());
	delete root;
	done = true;
	return realroot;
      }
       if (lr == 0) {
	cout << "Case 12" << endl;
	TreeNode* rootmoverright = root->getRight();
	while (rootmoverright->getLeft() != NULL) {
	rootmoverright = rootmoverright->getLeft();
      }
      rootmoverright->setLeft(root->getLeft());
      root = rootmoverright;
      done = true;
      return root;
      }
      

      
    }



  }
  if (done == false) {
  if (root->getLeft() != NULL) {
    //cout << "Test 1" << endl;
    remove (realroot, root->getLeft(), root, num, 1);
  }
  if (root->getRight() != NULL) {
    //cout << "Test 2" << endl;
    remove (realroot, root->getRight(), root, num, 2);

  }
  else {
    //    cout << "Number not found" << endl;
    return realroot;
  }
  }
  

}


int main() {
  bool running = true;
  int response = 0;
  cout << "Enter 1 for add, 2 for print, 3 for delete, and any other number to quit" << endl;
  cin >> response;
  TreeNode* root = NULL;
  while (running != false) {
  if (response == 1) {
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
   cout << "Enter 1 for add, 2 for print, and 3 for delete" << endl;
  cin >> response;
  }
  if (response == 2) {
  print(root);
 cout << "Enter 1 for add, 2 for print, and 3 for delete" << endl;
  cin >> response;
  }
  if (response == 3) {
    int numofnum = 0;
    int num = 0;
  int delcounter = 0;
  cout << "Enter how many numbers you want to delete" << endl;
  cin >> numofnum;
  cout << "Enter your numbers" << endl;
  while (delcounter != numofnum) {
    cin >> num;
    root = remove(root, root, NULL, num, 0);
       delcounter = delcounter + 1;
      }
  cout << "Done deleting" << endl;
   cout << "Enter 1 for add, 2 for print, and 3 for delete" << endl;
  cin >> response;

  }
}
  if (response != 1 && response != 2 && response != 3) {
    running = false;
    return 0;
  }
}
