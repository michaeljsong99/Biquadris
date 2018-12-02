
#include "block.h"
using namespace std;

Block::Block(char type, int position, int level) :type{type}, position{position},
                                                  x{0}, y{3}, levelCreated{level}  {
    setBlock();
}

void Block::setBlock() {
    if (type == 'I') {
        if (position == 1 || position == 3) {
            Cells.clear();
            Cells.emplace_back(Cell(0, 0, 'I'));
            Cells.emplace_back(Cell(1, 0, 'I'));
            Cells.emplace_back(Cell(2, 0, 'I'));
            Cells.emplace_back(Cell(3, 0, 'I'));
        } else {
            Cells.clear();
            Cells.emplace_back(Cell(0, 0, 'I'));
            Cells.emplace_back(Cell(0, 1, 'I'));
            Cells.emplace_back(Cell(0, 2, 'I'));
            Cells.emplace_back(Cell(0, 3, 'I'));
        }
    } else if (type == 'J') {
        if (position == 1) {
            Cells.clear();
            Cells.emplace_back(Cell(0, 0, 'J'));
            Cells.emplace_back(Cell(0, 1, 'J'));
            Cells.emplace_back(Cell(1, 0, 'J'));
            Cells.emplace_back(Cell(2, 0, 'J'));
        } else if (position == 2) {
            Cells.clear();
            Cells.emplace_back(Cell(0, 0, 'J'));
            Cells.emplace_back(Cell(0, 1, 'J'));
            Cells.emplace_back(Cell(0, 2, 'J'));
            Cells.emplace_back(Cell(1, 2, 'J'));
        } else if (position == 3) {
            Cells.clear();
            Cells.emplace_back(Cell(0, 1, 'J'));
            Cells.emplace_back(Cell(1, 1, 'J'));
            Cells.emplace_back(Cell(2, 1, 'J'));
            Cells.emplace_back(Cell(2, 0, 'J'));
        } else {
            Cells.clear();
            Cells.emplace_back(Cell(0, 0, 'J'));
            Cells.emplace_back(Cell(1, 0, 'J'));
            Cells.emplace_back(Cell(1, 1, 'J'));
            Cells.emplace_back(Cell(1, 2, 'J'));
        }
    } else if (type == 'L') {
        if (position == 1) {
            Cells.clear();
            Cells.emplace_back(Cell(0, 0, 'L'));
            Cells.emplace_back(Cell(1, 0, 'L'));
            Cells.emplace_back(Cell(2, 0, 'L'));
            Cells.emplace_back(Cell(2, 1, 'L'));
        } else if (position == 2) {
            Cells.clear();
            Cells.emplace_back(Cell(0, 0, 'L'));
            Cells.emplace_back(Cell(0, 1, 'L'));
            Cells.emplace_back(Cell(0, 2, 'L'));
            Cells.emplace_back(Cell(1, 0, 'L'));
        } else if (position == 3) {
            Cells.clear();
            Cells.emplace_back(Cell(0, 0, 'L'));
            Cells.emplace_back(Cell(0, 1, 'L'));
            Cells.emplace_back(Cell(1, 1, 'L'));
            Cells.emplace_back(Cell(2, 1, 'L'));
        } else {
            Cells.clear();
            Cells.emplace_back(Cell(0, 2, 'L'));
            Cells.emplace_back(Cell(1, 2, 'L'));
            Cells.emplace_back(Cell(1, 1, 'L'));
            Cells.emplace_back(Cell(1, 0, 'L'));
        }
    } else if (type == 'O') {
        Cells.clear();
        Cells.emplace_back(Cell(0, 0, 'O'));
        Cells.emplace_back(Cell(0, 1, 'O'));
        Cells.emplace_back(Cell(1, 0, 'O'));
        Cells.emplace_back(Cell(1, 1, 'O'));
    } else if (type == 'S') {
        if (position == 1 || position == 3) {
            Cells.clear();
            Cells.emplace_back(Cell(0, 0, 'S'));
            Cells.emplace_back(Cell(1, 0, 'S'));
            Cells.emplace_back(Cell(1, 1, 'S'));
            Cells.emplace_back(Cell(2, 1, 'S'));
        } else {
            Cells.clear();
            Cells.emplace_back(Cell(0, 1, 'S'));
            Cells.emplace_back(Cell(0, 2, 'S'));
            Cells.emplace_back(Cell(1, 0, 'S'));
            Cells.emplace_back(Cell(1, 1, 'S'));
        }
    } else if (type == 'Z') {
        if (position == 1 || position == 3) {
            Cells.clear();
            Cells.emplace_back(Cell(0, 1, 'Z'));
            Cells.emplace_back(Cell(1, 1, 'Z'));
            Cells.emplace_back(Cell(1, 0, 'Z'));
            Cells.emplace_back(Cell(2, 0, 'Z'));
        } else {
            Cells.clear();
            Cells.emplace_back(Cell(0, 0, 'Z'));
            Cells.emplace_back(Cell(0, 1, 'Z'));
            Cells.emplace_back(Cell(1, 1, 'Z'));
            Cells.emplace_back(Cell(1, 2, 'Z'));
        }
    } else if (type == 'T') {
        if (position == 1) {
            Cells.clear();
            Cells.emplace_back(Cell(0, 1, 'T'));
            Cells.emplace_back(Cell(1, 1, 'T'));
            Cells.emplace_back(Cell(2, 1, 'T'));
            Cells.emplace_back(Cell(1, 0, 'T'));
        } else if (position == 2) {
            Cells.clear();
            Cells.emplace_back(Cell(1, 2, 'T'));
            Cells.emplace_back(Cell(1, 1, 'T'));
            Cells.emplace_back(Cell(1, 0, 'T'));
            Cells.emplace_back(Cell(0, 1, 'T'));
        } else if (position == 3) {
            Cells.clear();
            Cells.emplace_back(Cell(0, 0, 'T'));
            Cells.emplace_back(Cell(1, 0, 'T'));
            Cells.emplace_back(Cell(2, 0, 'T'));
            Cells.emplace_back(Cell(1, 1, 'T'));
        } else {
            Cells.clear();
            Cells.emplace_back(Cell(0, 0, 'T'));
            Cells.emplace_back(Cell(0, 1, 'T'));
            Cells.emplace_back(Cell(0, 2, 'T'));
            Cells.emplace_back(Cell(1, 1, 'T'));
        }
    } else if (type == '*') {
        Cells.clear();
        Cells.emplace_back(Cell(0, 0, '*'));
    }


}

bool Block::isEmpty() {
    return Cells.empty();
}

void Block::moveLeft() {
    x--;
}

void Block::moveRight() {
    x++;
}

void Block::moveDown() {
    y++;
}

void Block::rotateCCW() {
    if(position == 1) {
        position = 4;
    }
    else position--;
    setBlock();
}

void Block::rotateCW() {
    if(position == 4) {
        position = 1;
    }
    else position++;
    setBlock();
}

void Block::printBlock(){
    vector<vector<Cell>> newGrid;
    Grid = newGrid;

    //Initializes Rows
    for(int i = 0; i < 4 ;++i) {
        Grid.push_back(vector<Cell>());
    }

    //Initializes Cells
    for(auto & i : Grid) {
        for (int j = 0; j < 4;++j) {
            i.push_back(Cell(0, 0, ' '));
        }
    }


    for(auto & k : Cells) {
        Grid[k.getY()][k.getX()] = k;
        //cout <<k.getY() <<k.getX();
    }
}

void Block::getPos() {
    cout << position;
}

int Block::getX() {
    return x;
}

int Block::getY() {
    return y;
}

void Block::setX(int x) {
    this->x = x;
}

void Block::setY(int y) {
    this->y = y;
}

ostream& operator<<(ostream &out, const Block &b) {

    for (auto & i : b.Grid) {
        for (auto & j : i) {
            out << j;
        }
        out << endl;
    }
    return out;
}

void Block::MoveDown(int row_number){
    int num_cells = this->Cells.size();
    for (int i = 0; i < num_cells; ++i) {
        if (Cells[i].getY() == row_number) {
            Cells[i].setLetter('\0');
        }
        if (Cells[i].getY() < row_number) {
            Cells[i].setY(Cells[i].getY() + 1);
        }
    }
}
