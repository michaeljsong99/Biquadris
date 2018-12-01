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


// FUNCTIONS FOR CLEARING ROWS AND UPDATING SCORE

bool is_row_full (<vector> Cell cells) {
    for (int i = 0; i < 11; ++ i) {
        if (cells[i].letter == '')
            return false;
    }
    return true;
}

bool CanClearOneRow() override {
    for (int row = 14; row >= 0; --row) {   // checks from the bottom row
        if (is_row_full(this->Grid[row])) {
            for (int r = row; r > 0; --r) {     // starts from the row to be cleared
                for (int col = 0; col < 11; ++col) {
                    this->Grid[r][col].letter = this->Grid[r-1][col].letter; // shifts everything down
                }
            }
            for (int col = 0; col < 11; ++ col) {
                this->Grid[0][col].letter = '';     // clears the top row
            }
        }
        return true;
    }
    return false;
}

int ClearRows() {           // recursively clears rows until no rows can be cleared
    int rows_cleared = 0;
    while (CanClearOneRow()) {
        ++rows_cleared;
    }
    return rows_cleared;    // returns the number of rows that were cleared
}

void calculateScore() override {
    int row_score = (ClearRows() + this.level);   // does this call ClearRows() ?
    int num_blocks = Blocks.size();     // number of blocks on the Board
    int block_score = 0;
    for (int i = 0; i < num_blocks; ++i) {
        int block_level = isBlockAlive(Blocks[i]);  // -1 if Block is dead, else level block was created
        block_score += ((block_level + 1) * (block_level + 1)); // will return 0 if block is alive
    }   
    return (row_score * row_score) + block_score;
}

int isBlockAlive(Block b) { // should be in Block.h/cc
    for (int i = 0; i < b.Cells.size(); ++i) {
        if (b.Cells[i].letter != '')
            return -1;    // returns -1 if one of the cells has a letter (as -1 + 1 = 0)
    }
    return b.levelCreated;
}

void update() {
    score += this.calculateScore();
    int num_blocks = Blocks.size();
    for (int i = 0; i < Blocks.size(); ++i) {
        if (isBlockAlive(Blocks[i]) == -1)
            delete Blocks[i];   // deletes a Block that is completely cleared
    }
}
