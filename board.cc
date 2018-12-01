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

    //Add Blocks
    for (auto & i : Blocks) {
        for (auto & j : i->Cells) {
            Grid[i->getY() + j.getY()][i->getY() + j.getX()] = j;
        }
    }

}

ostream& operator<<(ostream &out, const Board &b) {

    for (auto & i : b.Grid) {
        for (auto & j : i) {
            out << j;
        }
        out << endl;
    }
    return out;
}