#include "block.h"
#include "cell.h"
#include <iostream>

using namespace std;

int main() {
    string s;
    Cell c = Cell(0,0,'x');
    char l;
    cin >> l;
    Block b = Block(l, 1);
    b.printBlock();


    //Command Interpreter
    while(cin >> s) {

        if (s == "p") {
            b.printBlock();
            cout<< b;
            b.getPos();
        }
        else if (s == "r") {
            b.rotateCW();
            b.getPos();
        }
        else if (s == "rc") {
            b.rotateCCW();
            b.getPos();
        }
        else if (s == "printC") {
            cout << c;
        }
    }
}