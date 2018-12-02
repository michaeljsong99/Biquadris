#include <utility>

#include <iomanip>
#include <iostream>
#include <vector>
#include "cell.h"
#include "board.h"
#include <memory>
#include <sstream>

using namespace std;

void Board::endTurn() {
    updateGrid();

    if(isGameOver()) {
        cout << "Game Should Be Over!" << endl;
    }


    int rows = clearRows();
    cout << "Row Cleared" << endl;
    calculateScore(rows);

    if (hiscore < score) {
        hiscore = score;
    }
}

int Board::clearRows() {
    int rowsCleared = 0;
    int row = 2;
    bool flag = false;
    vector<int> rows;
    for (auto i = Grid.begin()+3; i !=Grid.end(); i++) {
        row++;
        for (auto & j : (*i)) {
            if(j.getLetter() == filler) {
                flag = true;
                break;
            }
        }

        if (flag) {
            flag = false;
            continue;
        }

        rows.emplace_back(row);
        rowsCleared++;
    }

    cout << "Found Filled Rows" << endl;

    for (auto & i : rows) {
        cout << i << endl;
        clearRow(i);
        cout << "Updating Grid" << endl;
        updateGrid();
        cout << "Updated Grid" << endl;
    }

    return rowsCleared;
}


void Board::clearRow(int row) {
    //Grid.e rase(Grid.begin()+row);


    for (auto & b : Blocks) {
        for (auto iter = b->Cells.begin(); iter != b->Cells.end();) {
            int y = b->getY() - iter->getY();
            cout << "y: " << y;

            if (y == row) {
                iter = b->Cells.erase(iter);
                cout << "   Cell Deleted" << endl;
                continue;
            } else if ((b->getY() >= row) && (y < row)) {
                iter->setY(iter->getY()-1);
                iter++;
                cout << "   Cell Shifted Down" << endl;
                continue;
            }
            cout << "   Cell Untouched" << endl;
            iter++;
        }
    }
    cout << "Changed Cell Coordinates" << endl;


    for (auto & b : Blocks) {
        if(b->getY() < row) {
            cout << "Block Y Set to " << b->getY()+1 << endl;
            b->setY(b->getY()+1);
        }
    }
    cout << "Changed Block Coordinates" << endl;

}

void Board::calculateScore(int rows) {
    int clearScore = level + rows;
    score += clearScore * clearScore;

    int blockScore = 0;
    for (auto b = Blocks.begin() ; b !=Blocks.end();) {
        Block & block = **b;
        if (block.isEmpty()) {
            int base = 1 + block.levelCreated;
            cout << "Add to baseScore: " << base * base << endl;
            blockScore += base * base;
            b = Blocks.erase(b);
        } else {
            b++;
        }
    }
    //cout << "clearScore: " << clearScore << endl;
    //cout << "blockScore: " << blockScore << endl;

    score += blockScore;
}

bool Board::isGameOver() {
    for (auto & c : cBlock->Cells) {
        int x = cBlock->getX() + c.getX();
        int y = cBlock->getY() - c.getY();
        if (Grid[y][x].getLetter() != filler) {
            return true;
        }
    }
    return false;
}


bool Board::canMoveLeft() {
    for (auto & c : cBlock->Cells) {
        int x = cBlock->getX() + c.getX();
        int y = cBlock->getY() - c.getY();

        if(x == 0) {
            return false;
        }

        if (Grid[y][x-1].getLetter() == filler) {
            continue;
        } else {
            return false;
        }
    }
    return true;
}


bool Board::canMoveRight() {
    for (auto & c : cBlock->Cells) {
        int x = cBlock->getX() + c.getX();
        int y = cBlock->getY() - c.getY();

        if(x == 10) {
            return false;
        }

        if (Grid[y][x+1].getLetter() == filler) {
            continue;
        } else {
            return false;
        }
    }
    return true;
}

bool Board::canMoveDown() {
    for (auto & c : cBlock->Cells) {
        int x = cBlock->getX() + c.getX();
        int y = cBlock->getY() - c.getY();

        if(y == 17) {
            return false;
        }

        if (Grid[y+1][x].getLetter() == filler) {
            continue;
        } else {
            return false;
        }
    }
    return true;
}

bool Board::canRotateCW() {
    cBlock->rotateCW();
    for (auto & c : cBlock->Cells) {
        int x = cBlock->getX() + c.getX();
        int y = cBlock->getY() - c.getY();

        if(y>17||y<0||x>10||x<0) {
            cBlock->rotateCCW();
            return false;
        }

        if (Grid[y][x].getLetter() == filler) {
            continue;
        } else {
            cBlock->rotateCCW();
            return false;
        }
    }
    cBlock->rotateCCW();
    return true;
};

bool Board::canRotateCCW() {
    cBlock->rotateCCW();
    for (auto & c : cBlock->Cells) {
        int x = cBlock->getX() + c.getX();
        int y = cBlock->getY() - c.getY();

        if(y>17||y<0||x>10||x<0) {
            cBlock->rotateCW();
            return false;
        }

        if (Grid[y][x].getLetter() == filler) {
            continue;
        } else {
            cBlock->rotateCW();
            return false;
        }
    }
    cBlock->rotateCW();
    return true;
};


void Board::setCurrentBlock(std::shared_ptr<Block> b) {
    this->cBlock = b;
}

void Board::setNextBlock(std::shared_ptr<Block> b) {
    this->nBlock = b;
}

void Board::drawCurrentBlock() {
    for (auto & c : cBlock->Cells) {
        int x = cBlock->getX() + c.getX();
        int y = cBlock->getY() - c.getY();
        Grid[y][x] = c;
    }
    //!Grid.erase(Grid.begin()+2);
}

void Board::drop() {
    while(canMoveDown()) {
        cBlock->moveDown();
    }
    addBlock(cBlock);
    cBlock = nBlock;
    endTurn();
    //!!!call update
}

void Board::addBlock(shared_ptr<Block> block) {
    Blocks.emplace_back(block);
}


void Board::updateGrid() {
    //Clears grid if applicable
    Grid.clear();


    vector <vector<Cell>> newGrid;
    Grid = newGrid;

    //Initializes Rows
    for (int by = 0; by < 18; ++by) {
        Grid.emplace_back(vector<Cell>());
    }

    //Initializes Cells
    for (int by = 0; by < 18; ++by) {
        for (int bx = 0; bx < 11; ++bx) {
            Grid[by].emplace_back(Cell(by, bx, filler));

        }
    }

    //cout << "Adding New Blocks: " << endl;


    //Add Blocks
    for (auto & b : Blocks) {
        for (auto & c : b->Cells) {
            //cout << "Y: " << b->getY() << "  " << c.getY() << "  " << b->getY() - c.getY() << endl;
            //cout << "X: " << b->getX() << "  " << c.getX() << "  " << b->getX() + c.getX() << endl;
            Grid[b->getY() - c.getY()][b->getX() + c.getX()] = c;
        }
    }

}

void Board::changeLevel(int change) {
    level += change;
}

int Board::getLevel() {
    return level;
}

std::string Board::printBoard() const {
    ostringstream oss;
    oss << "Level:" << setw(5) << level << endl;
    oss << "Score:" << setw(5) << score << endl;

    oss << "-----------" << endl;

    for (auto & i : Grid) {
        for (auto & j : i) {
            oss << j;
        }
        oss << endl;
    }

    oss << "-----------" << endl;
    oss << "Next:      " << endl;
    oss << nBlock->printBlock() << endl;

    return oss.str();
}

ostream& operator<<(ostream &out, const Board &b) {
    return out << b.printBoard();
}









