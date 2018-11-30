#include "block.h"
#include "cell.h"
#include <iostream>

using namespace std;

int main() {
    string s;
    Block b = Block('I', 1);
    Cell c = Cell(0,0,'x');
    b.printBlock();

    //Command Interpreter
    while(cin >> s) {

        if (s == "print") {

            cout<< b;
            b.getPos();
        }
        else if (s == "rotateCW") {
            b.rotateCW();
            b.getPos();
        }
        else if (s == "rotateCCW") {
            b.rotateCCW();
            b.getPos();
        }
        else if (s == "printC") {
            cout << c;
        }
    }
}