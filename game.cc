
#include "game.h"
#include <string>
#include <cstdlib>

Block Board::setBlock(int level) {
    string s;
    if (level == 0) {
        // still have to figure out how to read from given text files.
    }
    else if (level == 1) {
        int random = rand() % 11;    // returns random from 0-11
        string s;
        if (random == 0)
            s = "S";
        else if (random == 1)
            s = "Z";
        else if (random == 2 || random == 3)
            s = "I";
        else if (random == 4 || random == 5)
            s = "L;"
        else if (random == 6 || random == 7)
            s = "O";
        else if (random == 8 || random == 9)
            s = "T";
        else s = "J";
        return Block(s, level);
    }

    else if (level == 2) {
        int random = rand() % 6;    // returns random from 0-6
        string s;
        if (random == 0)
            s = "S";
        else if (random == 1)
            s = "Z";
        else if (random == 2)
            s = "I";
        else if (random == 3)
            s = "L";
        else if (random == 4)
            s = "O";
        else if (random == 5)
            s =  "T";
        else s = "J";
        return Block(s, level);
    }

    else {              // either level 3 or 4 
        int random = rand() % 8;    // returns random from 0-8
        string s;
        if (random == 0 || random == 1)
            s = "S";
        else if (random == 2 || random == 3)
            s = "Z";
        else if (random == 4)
            s = "I";
        else if (random == 5)
            s = "L";
        else if (random == 6)
            s = "O";
        else if (random == 7)
            s = "T";
        else s = "J";
        return Block(s, level);
    }
}
