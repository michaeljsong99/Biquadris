#include "heavy.h"


Heavy::Heavy(std::shared_ptr<AbstractBoard> ab, int heavy, bool isSA) : Decorator(ab), heavy{heavy}, isSA{isSA} {}
// Every time a block moves left or right, it automatically falls by two rows, after the horizontal move.
// If it is not possible for the block to drop two rows, it is considered to be dropped, and the turn ends.
// If the player is in a level where the blocks are heavy, the effect is cumulative (the player suffers from both effects).

// Note: My functions move the blocks in addition to returning a boolean value.

bool Heavy::moveLeft(int n) {                //Returns true if the block doesn't collide
    if (component->moveLeft(n)) {                       // if it is possible to move the block left
        for (int i = 0; i < heavy; ++i) {       // does the heaviness feature first
            if (component->shiftDown()) {
                continue;
            } else {
                drop();                         //ends the turn as it cannot move down further
                return true;                    //returns true as the left move is allowed.
            }
        }
    }
    return false;    // returns false if the left move is not legal.
}


bool Heavy::moveRight(int n) {
    if (component->moveRight(n)) {    // if it is possible to move the block right
        for (int i = 0; i < heavy; ++i) {    // does the heaviness feature first
            if (component->shiftDown()) {
                continue;
            } else {
                drop();    //ends the turn as it cannot move down further
                return true;    //returns true as the right move is allowed.
            }
        }
    }
    return false;    // returns false if the right move is not legal.
}

bool Heavy::moveDown(int n) {
    if(isSA) {
        component->moveDown(n);
    }

    if (component->moveDown(n)) {    // if it is possible to move the block down
        for (int i = 0; i < heavy; ++i) {    // does the heaviness feature first
            if (component->shiftDown()) {
                continue;
            } else {
                drop();    //ends the turn as it cannot move down further
                return true;    //returns true as the down move is allowed.
            }
        }
    }
    return false;    // returns false if the down move is not legal.
}

bool Heavy::rotateCW(int n) {      //Returns true if the block doesn't collide
    if(isSA) {
        component->rotateCW(n);
    }

    if (component->rotateCW(n)) {    // if it is possible to rotate CW// rotate CW
        for (int i = 0; i < heavy; ++i) {    // does the heaviness feature first
            if (component->shiftDown()) {
                continue;
            } else {
                drop();    //ends the turn as it cannot move down further
                return true;    //returns true as the down move is allowed.
            }
        }
    }
    return false;    // returns false if the rotate CW move is not legal.
}

bool Heavy::rotateCCW(int n) {        //Returns true if the block doesn't collide
    if(isSA) {
        component->rotateCCW(n);
    }

    if (component->rotateCCW(n)) {    // if it is possible to rotate CCW
        for (int i = 0; i < heavy; ++i) {    // does the heaviness feature first
            if (component->shiftDown()) {
                continue;
            } else {
                drop();    //ends the turn as it cannot move down further
                return true;    //returns true as the down move is allowed.
            }
        }
    }
    return false;    // returns false if the down move is not legal.
}

