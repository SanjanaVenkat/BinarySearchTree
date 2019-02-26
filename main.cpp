#include <iostream>
#include <cstring>

using namespace std;

void printTree(int numarray[], int numofnum);

void printTree(int numarray[], int numofnum) {
  int counter = 0;
  int n = 2;
  int x = 2^n;
  for (int i = 0; i < numofnum; i++) {
     cout << numarray[i] << " ";
    counter++;
    if (counter == 1) {
          cout << endl;
    }
    else if (counter != 1 && counter+1 == x) {
      cout << "TEST" << endl;
      //cout << counter+1 << " " << x << endl;
      n = n+1;
      x = 2^n;
       cout << endl;
    }

  }



}



int main() {
  int num;
  int i = 0;
  int numofnum = 0;
  int numarray[numofnum];
  bool done = false;
  cout << "Enter how many numbers you want to enter" << endl;
  cin >> numofnum;
  cout << "Enter numbers" << endl;
  while (done == false) {
    cin >> num; 
    numarray[i] = num;
    i++;
    if (i == numofnum) {
      done = true;
    }
  }
  printTree(numarray, numofnum);
  return 0;

}
