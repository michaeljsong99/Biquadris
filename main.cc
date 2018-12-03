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
    string c; // to store the command
    ifstream readFile;
    bool isFile = false;
    while (true) {

        if (!isFile) {
            cin >> c;
        } else {
            if (!(readFile >> c)) {
                isFile = false;
                cin >> c;
            }
        }

        if (c == "left") {
            g.moveBlock('l', turn, 1);
            cout << g;
        } else if (c == "right") {
            g.moveBlock('r', turn, 1);
            cout << g;
        } else if (c == "down") {
            g.moveBlock('d', turn, 1);
            cout << g;
        } else if (c == "clockwise") {
            g.rotateBlock('c', turn, 1);
            cout << g;
        } else if (c == "counterclockwise") {
            g.rotateBlock('w', turn, 1);
            cout << g;
        } else if (c == "drop") {
            g.drop(1);
        } else if (c == "levelup") {

        } else if (c == "leveldown") {

        } else if (c == "norandom") {
            string f;
            cin >> f;
            //norandom
            //file name
        } else if (c == "random") {

        } else if (c == "sequence") {
            string f;
            cin >> f;
            //sequence
            //file
            //name
                    //readFile{f};
            isFile = true;
        } else if (cin.eof()){
            break;
        }
    }
}
