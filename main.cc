#include <iostream>
#include <sstream>
#include <string>
#include "game.h"
#include "window.h"


using namespace std;

void readCommand(int& n, string& s, vector<string>& commands) {
    while (true) {
        cin >> s;
        if (cin.eof()) {
            break;
        }
        int counter = 0;
        while (s[counter] >= '0' && s[counter] <= '9') {
            counter++;
        }
        if (counter != 0) {
            n = stoi(s.substr(0, counter));
        } else {
            n = 1;
        }
        s = s.substr(counter);
        cout << n << " " << s << endl;

        vector<string> matches;
        for (auto &in : commands) {
            if (s.length() > in.length()) {
                continue;
            }
            if (in.substr(0, s.length()) == s) {
                matches.emplace_back(in);
            }

        }
        if(matches.size() == 1) {
            s = matches.back();
            break;

        }
        else if(matches.size() > 1) {
            cout << "Matches too many of the following commands. PLease try again." << endl;
            for(auto &in : matches) {
                cout << in << endl;

            }
        }else {
            cout << "No match found. Please try again" << endl;
        }
    }
}

void commandLoop(Game &g) {
    //Store all commands
    vector<string> commands;
    commands.emplace_back("left");
    commands.emplace_back("right");
    commands.emplace_back("down");
    commands.emplace_back("clockwise");
    commands.emplace_back("counterclockwise");
    commands.emplace_back("drop");
    commands.emplace_back("levelup");
    commands.emplace_back("leveldown");
    commands.emplace_back("norandom");
    commands.emplace_back("random");
    commands.emplace_back("sequence");
    commands.emplace_back("restart");
    commands.emplace_back("I");
    commands.emplace_back("J");
    commands.emplace_back("L");
    commands.emplace_back("S");
    commands.emplace_back("Z");
    commands.emplace_back("O");
    commands.emplace_back("T");

    int n;
    string s;
    vector<string>& com = commands;



    g.init();
    int turn = 1;
    string file;

    bool isSequence = false;
    ifstream sequence;
    cout << g;

    while (true) {

        if (!isSequence) {
            readCommand(n, s, com);
        } else {
            if (!(sequence >> s)) {
                isSequence = false;
                cin >> s;
            }
        }
        while(n > 0) {
            if (s == "left") {
                g.moveBlock('l', turn, 1);
                n--;
            } else if (s == "right") {
                g.moveBlock('r', turn, 1);
                n--;
            } else if (s == "down") {
                g.moveBlock('d', turn, 1);
                n--;
            } else if (s == "clockwise") {
                g.rotateBlock('c', turn, 1);
                n--;
            } else if (s == "counterclockwise") {
                g.rotateBlock('w', turn, 1);
                n--;
            } else if (s == "drop") {
                g.drop(turn);

                if (turn == 1) {
                    turn = 2;
                } else {
                    turn = 1;
                }
                n--;
            } else if (s == "levelup") {
                g.changeLevel(1, turn);
                n--;
            } else if (s == "leveldown") {
                g.changeLevel(-1, turn);
                n--;
            } else if (s == "norandom") {
                g.setRandom(false);
                cin >> file;
                g.setFileRandom(file);
                n=0;
            } else if (s == "random") {
                g.setRandom(true);
                n=0;
            } else if (s == "sequence") {
                cin >> file;
                sequence = ifstream(file);
                isSequence = true;
                n=0;
            } else if (s == "I" || s == "J" || s == "L" || s == "Z" || s == "S" || s == "O" || s == "T") {
                char c = s[0];
                g.replaceBlock(c, turn);
                n=0;
            } else if (s == "restart") {
                g.resetBoard();
                n=0;
            }
            turn = g.checkTurn();
            cout << g;
        }

        if (cin.eof()) {
            break;
        }


    }
}

void graphicsGame(string& file1, string& file2, int& level) {
    Xwindow xw(500, 700);
    Game g = Game(&xw); // call the game constructor(implementation still absent from the game class)
    g.setGraphics(true);
    if(!file1.empty()) {
        g.setFile1(file1);
    }
    if(!file2.empty()) {
        g.setFile2(file2);
    }
    if(level != -1) {
        g.setLevel(level);
    }
    commandLoop(g);
}

void textGame(string& file1, string& file2, int& level) {
    Game g = Game(nullptr);
    g.setGraphics(false);
    if(!file1.empty()) {
        g.setFile1(file1);
    }
    if(!file2.empty()) {
        g.setFile2(file2);
    }
    if(level != -1) {
        g.setLevel(level);
    }
    commandLoop(g);
}

int main(int argc, char *argv[]) {
    bool graphics;
    string file1;
    string file2;
    int level = -1;


    for (int i = 1; i < argc; i++) {
        if (string(argv[i]) == "-text") {
            graphics = false;
        } else if (string(argv[i]) == "-seed") {
            i++;
            int seed = stoi(string(argv[i]));
            srand(seed);
        } else if (string(argv[i]) == "-scriptfile1") {
            i++;
            file1 = string(argv[i]);
        } else if (string(argv[i]) == "-scriptfile2") {
            i++;
            file2 = string(argv[i]);
        } else if (string(argv[i]) == "-startlevel") {
            i++;
            level = stoi(argv[i]);
        }
    }

    if(graphics) {
        graphicsGame(file1, file2, level);
    } else {
        textGame(file1, file2, level);
    }
}
