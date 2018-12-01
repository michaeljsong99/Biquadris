#include "block.h"
#include <iostream>
#include <string>
using namespace std;

//NOTE: To successfully create a block, besides initialization, the client must also call setBlock method.
//Also, if the client wants to know the current position of each cell in the block, then just access x, y values of each cell in the container field
// Below is a demonstration of how to use the Block Class.
int main() {
 string s;
 cin >> s;
 Block b{s,0};// initializaation
 b.setBlock();// call setBlock method
 // the block has been successfully created
 cout << b << endl;// print the block
 while(true) {
   cin >> s;
   if (s == "rotateCW") {
     b.rotateCW(); // rotate Clockwise
   } else if (s == "rotateCCW") {
     b.rotateCCW(); //rotate counter-clockwise
   } else if (s == "print") {
     cout << b << endl;
   } else {
     break;
   }
 }
}
