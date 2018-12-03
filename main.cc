#include <iostream>
#include <sstream>
#include <string>
#include "game.h"

using namespace std;

int main(int argc, char *argv[]) {
    Game g = Game(); // call the game constructor(implementation still absent from the game class)

    for (int i = 1; i < argc; i++) {
        if (string(argv[i]) == "-text") {
            g.setGraphics(false);
        } else if (string(argv[i]) == "-seed") {
            i++;
            int seed = stoi(string(argv[i]));
            srand(seed);
        } else if (string(argv[i]) == "-scriptfile1") {
            i++;
            g.setFile1(string(argv[i]));
        } else if (string(argv[i]) == "-scriptfile2") {
            i++;
            g.setFile2(string(argv[i]));
        } else if (string(argv[i]) == "-startLevel") {
            i++;
            int level = stoi(argv[i]);
            g.setLevel(level);
        }
    }
    cout << "Command Line Initialized" << endl;




    g.setLevel(1);
    g.init();


    int turn = 1;
    string s; // to store the command
    string file;

    bool isFile = false;
    ifstream sequence;

    while (true) {
        cout << g;

        if (!isFile) {
            cin >> s;
        } else {
            if (!(sequence >> s)) {
                isFile = false;
                cin >> s;
            }
        }

        if (s == "left") {
            g.moveBlock('l', turn, 1);
        }
        else if (s == "right") {
            g.moveBlock('r', turn, 1);
        }
        else if (s == "down") {
            g.moveBlock('d', turn, 1);
        }
        else if (s == "clockwise") {
            g.rotateBlock('c', turn, 1);
        }
        else if (s == "counterclockwise") {
            g.rotateBlock('w', turn, 1);
        }
        else if (s == "drop") {
            g.drop(turn);

            if (turn == 1) {
                turn = 2;
            } else {
                turn = 1;
            }
        }
        else if (s == "levelup") {
            g.changeLevel(1, turn);
        }
        else if (s == "leveldown") {
            g.changeLevel(-1, turn);
        }
        else if (s == "norandom") {
            g.setRandom(false);
            cin >> file;
            g.setFileRandom(file);
        }
        else if (s == "random") {
            g.setRandom(true);
        }
        else if (s == "sequence") {
            cin >> file;
            sequence =ifstream(file);
            isFile = true;
        }
        else if (s == "I" || s == "J" || s == "L" || s == "Z" || s == "S" || s == "O" || s == "T") {
            char c = s[0];
            g.replaceBlock(c, turn);
        }
        else if (s == "restart") {
            g.resetBoard();

        }
        else if (cin.eof()){
            break;
        }
    }
}
