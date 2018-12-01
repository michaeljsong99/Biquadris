#include <vector>
#include "cell.h"
#include "board.h"

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

