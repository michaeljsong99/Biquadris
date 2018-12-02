
#include "block.h"
#include "cell.h"
#include "board.h"
#include <iostream>
#include <memory>

using namespace std;

int main() {
    string s;
    char c;
    cin >> c;
    int n;

    auto b1 = make_shared<Block>(c, 1, 0);
    //b1->setX(3);
    //b1->setY(4);


    Board b;
    b.setCurrentBlock(b1);
    //b.addBlock(test);
    b.updateGrid();
    b.drawCurrentBlock();
    cout <<b;
    b.updateGrid();

    //Command Interpreter
    while(cin >> s) {

        if (s == "ml") {
            b.updateGrid();
            cout << b.canMoveLeft() << endl;
            if (b.canMoveLeft()) {
                b1->moveLeft();
            }
            b.drawCurrentBlock();
            cout << b;
            b.updateGrid();
        }
        else if (s == "mr") {
            b.updateGrid();
            cout << b.canMoveRight() << endl;
            if (b.canMoveRight()) {
                b1->moveRight();
            }
            b.drawCurrentBlock();
            cout << b;
            b.updateGrid();
        }
        else if (s == "md") {
            b.updateGrid();
            cout << b.canMoveDown() << endl;
            if (b.canMoveDown()) {
                b1->moveDown();
            }
            b.drawCurrentBlock();
            cout << b;
            b.updateGrid();
        }
        else if (s == "rc") {
            b.updateGrid();
            cout << b.canRotateCW() << endl;
            if (b.canRotateCW()) {
                cout<<"Rotated!"<<endl;
                b1->rotateCW();
            }
            b.drawCurrentBlock();
            cout << b;
            b.updateGrid();
        }
        else if (s == "rw") {
            b.updateGrid();
            cout << b.canRotateCCW() << endl;
            if (b.canRotateCCW()) {
                cout<<"Rotated!"<<endl;
                b1->rotateCCW();
            }
            b.drawCurrentBlock();
            cout << b;
            b.updateGrid();
        }
        else if (s == "drop") {
            cin >> c ;
            b.drop();
            b.updateGrid();
            auto temp = make_shared<Block>(c, 1, b.getLevel());
            b.setCurrentBlock(temp);
            b1 = temp;
            b.drawCurrentBlock();
            cout << b;
            b.updateGrid();
        }
        else if (s == "level") {
            cin >> n ;
            b.changeLevel(n);
            b.updateGrid();
            b.drawCurrentBlock();
            cout << b;
            b.updateGrid();
        }
    }




}
