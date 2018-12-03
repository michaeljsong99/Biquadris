#include <utility>

#include <iomanip>
#include <iostream>
#include <vector>
#include "cell.h"
#include "board.h"
#include <memory>
#include <sstream>

using namespace std;

Board::Board(Xwindow *xw) : xw{xw} {}

void Board::endTurn() {
    updateGrid();

    int rows = clearRows();
    //cout << "Row Cleared" << endl;
    calculateScore(rows);

    if (hiscore < score) {
        hiscore = score;
    }
    dropped = true;
    rowsCleared = rows;
    //cout << rowsCleared << endl;
}

void Board::calculateScore(int rows) {
    if (rows > 0) {
        int clearScore = level + rows;
        score += clearScore * clearScore;
    }

    int blockScore = 0;
    for (auto b = Blocks.begin(); b != Blocks.end();) {
        Block &block = **b;
        if (block.isEmpty()) {
            int base = 1 + block.levelCreated;
            //cout << "Add to baseScore: " << base * base << endl;
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

int Board::clearRows() {
    int rowsCleared = 0;
    int row = 2;
    bool flag = false;
    vector<int> rows;
    for (auto i = Grid.begin() + 3; i != Grid.end(); i++) {
        row++;
        for (auto &j : (*i)) {
            if (j.getLetter() == filler) {
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

    //cout << "Found Filled Rows" << endl;

    for (auto &i : rows) {
        //cout << i << endl;
        clearRow(i);
        //cout << "Updating Grid" << endl;
        updateGrid();
        //cout << "Updated Grid" << endl;
    }

    return rowsCleared;
}

void Board::clearRow(int row) {
    //Grid.e rase(Grid.begin()+row);


    for (auto &b : Blocks) {
        for (auto iter = b->Cells.begin(); iter != b->Cells.end();) {
            int y = b->getY() - iter->getY();
            //cout << "y: " << y;

            if (y == row) {
                iter = b->Cells.erase(iter);
                //cout << "   Cell Deleted" << endl;
                continue;
            } else if ((b->getY() >= row) && (y < row)) {
                iter->setY(iter->getY() - 1);
                iter++;
                //cout << "   Cell Shifted Down" << endl;
                continue;
            }
            //cout << "   Cell Untouched" << endl;
            iter++;
        }
    }
    //cout << "Changed Cell Coordinates" << endl;


    for (auto &b : Blocks) {
        if (b->getY() < row) {
            //cout << "Block Y Set to " << b->getY() + 1 << endl;
            b->setY(b->getY() + 1);
        }
    }
    //cout << "Changed Block Coordinates" << endl;

}

bool Board::isGameOver() {
    for (auto &c : cBlock->Cells) {
        int x = cBlock->getX() + c.getX();
        int y = cBlock->getY() - c.getY();
        if (Grid[y][x].getLetter() != filler) {
            return true;
        }
    }
    return false;
}

void Board::setCurrentBlock(std::shared_ptr<Block> b) {
    this->cBlock = b;
}

void Board::setNextBlock(std::shared_ptr<Block> b) {
    this->nBlock = b;
}

void Board::addBlock(shared_ptr<Block> b) {
    Blocks.emplace_back(b);
}

void Board::drawCurrentBlock() {
    for (auto &c : cBlock->Cells) {
        int x = cBlock->getX() + c.getX();
        int y = cBlock->getY() - c.getY();
        Grid[y][x] = c;
    }
    //!Grid.erase(Grid.begin()+2);
}

bool Board::canMoveLeft(int n) {
    while (n > 0) {
        n--;
        for (auto &c : cBlock->Cells) {
            int x = cBlock->getX() + c.getX();
            int y = cBlock->getY() - c.getY();

            if (x == 0) {
                return false;
            }
            x--;
            if (Grid[y][x].getLetter() == filler) {
                continue;
            } else {
                return false;
            }
        }
    }
    updateGrid();
    return true;
}

bool Board::canMoveRight(int n) {
    while (n > 0) {
        n--;
        for (auto &c : cBlock->Cells) {
            int x = cBlock->getX() + c.getX();
            int y = cBlock->getY() - c.getY();

            if (x == width) {
                return false;
            }
            x++;
            if (Grid[y][x].getLetter() == filler) {
                continue;
            } else {
                return false;
            }
        }
    }
    updateGrid();
    return true;
}

bool Board::canMoveDown(int n) {
    while (n > 0) {
        n--;
        for (auto &c : cBlock->Cells) {
            int x = cBlock->getX() + c.getX();
            int y = cBlock->getY() - c.getY();

            if (y == height) {
                return false;
            }
            y++;
            if (Grid[y][x].getLetter() == filler) {
                continue;
            } else {
                return false;
            }
        }
    }
    updateGrid();
    return true;
}

bool Board::canRotateCW(int n) {
    if (n > 4) {
        n = 4;
    }
    for (int i = 0; i < n; i++) {
        cBlock->rotateCW(n);
        for (auto &c : cBlock->Cells) {
            int x = cBlock->getX() + c.getX();
            int y = cBlock->getY() - c.getY();

            if (y > height || y < 0 || x > width || x < 0) {
                cBlock->rotateCCW(n);
                return false;
            }

            if (Grid[y][x].getLetter() == filler) {
                continue;
            } else {
                cBlock->rotateCCW(n);
                return false;
            }
        }
        cBlock->rotateCCW(n);
    }
    updateGrid();
    return true;
};

bool Board::canRotateCCW(int n) {
    if (n > 4) {
        n = 4;
    }
    for (int i = 0; i < n; i++) {
        cBlock->rotateCCW(n);
        for (auto &c : cBlock->Cells) {
            int x = cBlock->getX() + c.getX();
            int y = cBlock->getY() - c.getY();

            if (y > height || y < 0 || x > width || x < 0) {
                cBlock->rotateCW(n);
                return false;
            }

            if (Grid[y][x].getLetter() == filler) {
                continue;
            } else {
                cBlock->rotateCW(n);
                return false;
            }
        }
        cBlock->rotateCW(n);
    }
    updateGrid();
    return true;
};

bool Board::moveRight(int n) {
    bool b = canMoveRight(n);
    if (b) {
        cBlock->moveRight(n);
    }
    return b;
}

bool Board::moveLeft(int n) {
    bool b = canMoveLeft(n);
    if (b) {
        cBlock->moveLeft(n);
    }
    return b;
}

bool Board::moveDown(int n) {
    bool b = canMoveDown(n);
    if (b) {
        cBlock->moveDown(n);
    }
    return b;
}

bool Board::rotateCW(int n) {
    bool b = canRotateCW(n);
    if (b) {
        cBlock->rotateCW(n);
    }
    return b;
}

bool Board::rotateCCW(int n) {
    bool b = canRotateCCW(n);
    if (b) {
        cBlock->rotateCCW(n);
    }
    return b;
}

bool Board::shiftDown() {
    return moveDown(1);
}

void Board::drop() {
    //cout << "Moving Down" << endl;
    while (moveDown(1)) {
    }
    //cout << "Moved to the Bottom!" << endl;
    addBlock(cBlock);
    cBlock = nBlock;
    endTurn();
    //!!!call update
}

void Board::reset() {
    score = 0;
    cBlock = nullptr;
    nBlock = nullptr;
    Blocks.clear();
    Grid.clear();
}

void Board::updateGrid() {
    //Clears grid if applicable
    Grid.clear();


    vector<vector<Cell>> newGrid;
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
    for (auto &b : Blocks) {
        for (auto &c : b->Cells) {
            //cout << "Y: " << b->getY() << "  " << c.getY() << "  " << b->getY() - c.getY() << endl;
            //cout << "X: " << b->getX() << "  " << c.getX() << "  " << b->getX() + c.getX() << endl;
            Grid[b->getY() - c.getY()][b->getX() + c.getX()] = c;
        }
    }

}

int Board::getScore() {
    return score;
}

int Board::getLevel() {
    return level;
}

void Board::setLevel(int n) {
    level = n;
}

void Board::changeLevel(int change) {
    level += change;
    if(level < 0) {
        level = 0;
    }
    if (level > 4) {
        level = 4;
    }
}

void Board::setHeavy(int n) {

};

bool Board::getDropped() {
    return dropped;
}

void Board::setDropped(bool b) {
    dropped = b;
}

int Board::getRowsCleared() {
    return rowsCleared;
}

std::shared_ptr<AbstractBoard> Board::removeDecorator() {
    return nullptr;
}

void Board::dropMiddle() {
    auto nb = make_shared<Block>('*', 1, -1);

    int y = 0;
    while(true) {
        if(y == height) {
            break;
        }

        if (Grid[y+1][5].getLetter() == filler) {
            y++;
            continue;
        } else {
            break;
        }
    }
    nb->setY(y);
    nb->setX(5);
    addBlock(nb);
}

std::string Board::printBoard() const {
    ostringstream oss;
    oss << "Level:" << setw(5) << level << endl;
    oss << "Score:" << setw(5) << score << endl;

    oss << "-----------" << endl;

    for (auto &i : Grid) {
        for (auto &j : i) {
            oss << j;
        }
        oss << endl;
    }

    oss << "-----------" << endl;
    oss << "Next:      " << endl;
    oss << nBlock->printBlock() << endl;

    return oss.str();
}

void Board::drawBoard(int baseX, int baseY) const{

    xw->drawString(baseX, baseY+20, "Level:");
    xw->drawString(baseX, baseY+40, "Score:");
    xw->drawString(baseX+50, baseY+20, to_string(level));
    xw->drawString(baseX+50, baseY+40, to_string(score));

    baseY += 50;
    int y;
    int x;
    xw->fillRectangle(baseX, baseY, 220, 520, Xwindow::White);
    for (y = 0; y <= height ; y++) {
        for (x = 0; x <= width; x++) {
            char letter = Grid[y][x].getLetter();
            //cout << "Drawing " << letter << " x " << x << " y " << y <<  endl;
            if(letter == 'I') {
                xw->fillRectangle(baseX + (side*x), baseY + (side*y), side, side, Xwindow::Cyan);
            } else if(letter == 'J') {
                xw->fillRectangle(baseX + (side*x), baseY + (side*y), side, side, Xwindow::Orange);
            } else if(letter == 'L') {
                xw->fillRectangle(baseX + (side*x), baseY + (side*y), side, side, Xwindow::Blue);
            } else if(letter == 'T') {
                xw->fillRectangle(baseX + (side*x), baseY + (side*y), side, side, Xwindow::Magenta);
            } else if(letter == 'O') {
                xw->fillRectangle(baseX + (side*x), baseY + (side*y), side, side, Xwindow::Yellow);
            } else if(letter == 'S') {
                xw->fillRectangle(baseX + (side*x), baseY + (side*y), side, side, Xwindow::Green);
            } else if(letter == 'Z') {
                xw->fillRectangle(baseX + (side*x), baseY + (side*y), side, side, Xwindow::Red);
            } else if(letter == '*') {
                xw->fillRectangle(baseX + (side*x), baseY + (side*y), side, side, Xwindow::Brown);
            } else {
                xw->fillRectangle(baseX + (side*x), baseY + (side*y), side, side, Xwindow::Black);
            }

        }
    }
    xw->drawString(baseX, 30+baseY + (side*y), "Next:");
    nBlock->drawBlock(baseX, baseY+(side*y)+50, side, xw);
    cout << baseY+(side*y)+50 << endl;
}

ostream &operator<<(ostream &out, const Board &b) {
    return out << b.printBoard();
}









