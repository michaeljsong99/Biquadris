#include <vector>
#include "cell.h"
#include "board.h"
// NOTE: Blocks was changed to a vector of pointers to Blocks, not just a vector of Blocks anymore.


using namespace std;

void Board::updateGrid() {
    //Clears grid if applicable
    Grid.clear();


    vector <vector<Cell>> newGrid;
    Grid = newGrid;

    //Initializes Rows
    for (int i = 0; i < 15; ++i) {
        Grid.emplace_back(vector<Cell>());
    }

    //Initializes Cells
    for (int i = 0; i < 15; ++i) {
        for (int j = 0; j < 11; ++j) {
            Grid[i].emplace_back(Cell(i, j, '*'));

        }
    }
}

*/

// FUNCTIONS FOR CLEARING ROWS AND UPDATING SCORE
bool is_row_full (std::vector<Cell> cells) {
    for (int i = 0; i < 11; ++ i) {
        if (cells[i].getLetter())
            return false;
    }
    return true;
}

bool Board::CanClearOneRow() {
    for (int row = 14; row >= 0; --row) {   // checks from the bottom row
        if (is_row_full(this->BoardGrid[row])) {
            for (int r = row; r > 0; --r) {     // starts from the row to be cleared
                for (int col = 0; col < 11; ++col) {
                    this->BoardGrid[r][col].setLetter(this->BoardGrid[r-1][col].getLetter()); // shifts everything down
                }
            }
            for (int col = 0; col < 11; ++ col) {
                this->BoardGrid[0][col].setLetter('\0');     // clears the top row
            }
	    int num_blocks = this->Blocks.size();
	    for (int i = 0; i < num_blocks; ++i) {
	        Blocks[i]->MoveDown(row);
	    }
        }
        return true;
    }
    return false;
}

int Board::ClearRows() {           // recursively clears rows until no rows can be cleared
    int rows_cleared = 0;
    while (this->CanClearOneRow()) {
        ++rows_cleared;
    }
    return rows_cleared;    // returns the number of rows that were cleared
}

int Board::CalculateScore() { // override {
    int row_score = (this->ClearRows() + this->level);   // does this call ClearRows() ?
    int num_blocks = this->Blocks.size();     // number of blocks on the Board
    int block_score = 0;
    for (int i = 0; i < num_blocks; ++i) {
        int block_level = (Blocks[i]->isBlockAlive());  // -1 if Block is dead, else level block was created
        block_score += ((block_level + 1) * (block_level + 1)); // will return 0 if block is alive
    }
    int add_score = (row_score * row_score) + block_score;   
    this->score += add_score;
    return add_score;
}

void Board::update() {
    if (score > hi_score) {
	hi_score = score;
    }
    int num_blocks = Blocks.size();
    for (int i = 0; i < num_blocks; ++i) {
        if ((Blocks[i]->isBlockAlive()) == -1)
             Blocks.erase(Blocks.begin() + i);   // erases a Block that is completely cleared
    }
}

