#include <cstdlib>
#include "board.h"

Block Board::setBlock(int level) {
    if (level == 0) {
        // still have to figure out how to read from given text files.
    }
    else if (level == 1) {
        int random = rand() % 11;    // returns random from 0-11
        if (random == 0)
            Block b("S", level)// not sure how to return a Block
        else if (random == 1)
            return Z;
        else if (random == 2 || random == 3)
            return I;
        else if (random == 4 || random == 5)
            return L;
        else if (random == 6 || random == 7)
            return O;
        else if (random == 8 || random == 9)
            return T;
        else return J;
    }

    else if (level == 2) {
        int random = rand() % 6;    // returns random from 0-6
        if (random == 0)
            return S;
        else if (random == 1)
            return Z;
        else if (random == 2)
            return I;
        else if (random == 3)
            return L;
        else if (random == 4)
            return O;
        else if (random == 5)
            return T;
        else return J;
    }

    else {              // either level 3 or 4 
        int random = rand() % 8;    // returns random from 0-8
        if (random == 0 || random == 1)
            return S;
        else if (random == 2 || random == 3)
            return Z;
        else if (random == 4)
            return I;
        else if (random == 5)
            return L;
        else if (random == 6)
            return O;
        else if (random == 7)
            return T;
        else return J;
    }
}
