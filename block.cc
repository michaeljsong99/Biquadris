
#include "block.h"
using namespace std;

Block::Block(char type) :type{type}, position{position}  {
    setBlock();
    x = 0;
    y = 0;
}

void Block::setBlock() {
    if (type == 'I') {

        if (position == 2 || position == 4) {
            Cells.clear();
            Cells.emplace_back(Cell(0, 0, 'I'));
            Cells.emplace_back(Cell(0, 1, 'I'));
            Cells.emplace_back(Cell(0, 2, 'I'));
            Cells.emplace_back(Cell(0, 3, 'I'));
        } else {
            Cells.clear();
            Cells.emplace_back(Cell(0, 3, 'I'));
            Cells.emplace_back(Cell(1, 3, 'I'));
            Cells.emplace_back(Cell(2, 3, 'I'));
            Cells.emplace_back(Cell(3, 3, 'I'));
        }
    } else if (type == 'J') {
        if (position == 1) {
            Cells.clear();
            Cells.emplace_back(Cell(0, 2, 'J'));
            Cells.emplace_back(Cell(0, 3, 'J'));
            Cells.emplace_back(Cell(1, 3, 'J'));
            Cells.emplace_back(Cell(2, 3, 'J'));
        } else if (position == 2) {
            Cells.clear();
            Cells.emplace_back(Cell(0, 2, 'J'));
            Cells.emplace_back(Cell(0, 3, 'J'));
            Cells.emplace_back(Cell(0, 1, 'J'));
            Cells.emplace_back(Cell(1, 1, 'J'));
        } else if (position == 3) {
            Cells.clear();
            Cells.emplace_back(Cell(0, 2, 'J'));
            Cells.emplace_back(Cell(1, 2, 'J'));
            Cells.emplace_back(Cell(2, 2, 'J'));
            Cells.emplace_back(Cell(2, 3, 'J'));
        } else {
            Cells.clear();
            Cells.emplace_back(Cell(1, 1, 'J'));
            Cells.emplace_back(Cell(1, 2, 'J'));
            Cells.emplace_back(Cell(1, 3, 'J'));
            Cells.emplace_back(Cell(0, 3, 'J'));
        }
    } else if (type == 'L') {
        if (position == 1) {
            Cells.clear();
            Cells.emplace_back(Cell(2, 2, 'L'));
            Cells.emplace_back(Cell(0, 3, 'L'));
            Cells.emplace_back(Cell(1, 3, 'L'));
            Cells.emplace_back(Cell(2, 3, 'L'));
        } else if (position == 2) {
            Cells.clear();
            Cells.emplace_back(Cell(0, 2, 'L'));
            Cells.emplace_back(Cell(0, 3, 'L'));
            Cells.emplace_back(Cell(0, 1, 'L'));
            Cells.emplace_back(Cell(1, 3, 'L'));
        } else if (position == 3) {
            Cells.clear();
            Cells.emplace_back(Cell(0, 2, 'L'));
            Cells.emplace_back(Cell(1, 2, 'L'));
            Cells.emplace_back(Cell(2, 2, 'L'));
            Cells.emplace_back(Cell(0, 3, 'L'));
        } else {
            Cells.clear();
            Cells.emplace_back(Cell(1, 1, 'L'));
            Cells.emplace_back(Cell(1, 2, 'L'));
            Cells.emplace_back(Cell(1, 3, 'L'));
            Cells.emplace_back(Cell(0, 1, 'L'));
        }
    } else if (type == 'O') {
        Cells.clear();
        Cells.emplace_back(Cell(0, 2, 'O'));
        Cells.emplace_back(Cell(0, 3, 'O'));
        Cells.emplace_back(Cell(1, 2, 'O'));
        Cells.emplace_back(Cell(1, 3, 'O'));
    } else if (type == 'S') {
        if (position == 1 || position == 3) {
            Cells.clear();
            Cells.emplace_back(Cell(0, 3, 'S'));
            Cells.emplace_back(Cell(1, 3, 'S'));
            Cells.emplace_back(Cell(1, 2, 'S'));
            Cells.emplace_back(Cell(2, 2, 'S'));
        } else {
            Cells.clear();
            Cells.emplace_back(Cell(0, 1, 'S'));
            Cells.emplace_back(Cell(0, 2, 'S'));
            Cells.emplace_back(Cell(1, 2, 'S'));
            Cells.emplace_back(Cell(1, 3, 'S'));
        }
    } else if (type == 'Z') {
        if (position == 1 || position == 3) {
            Cells.clear();
            Cells.emplace_back(Cell(0, 2, 'Z'));
            Cells.emplace_back(Cell(1, 2, 'Z'));
            Cells.emplace_back(Cell(1, 3, 'Z'));
            Cells.emplace_back(Cell(2, 3, 'Z'));
        } else {
            Cells.clear();
            Cells.emplace_back(Cell(0, 2, 'Z'));
            Cells.emplace_back(Cell(0, 3, 'Z'));
            Cells.emplace_back(Cell(1, 1, 'Z'));
            Cells.emplace_back(Cell(1, 2, 'Z'));
        }
    } else if (type == 'T') {
        if (position == 1) {
            Cells.clear();
            Cells.emplace_back(Cell(0, 2, 'T'));
            Cells.emplace_back(Cell(1, 2, 'T'));
            Cells.emplace_back(Cell(2, 2, 'T'));
            Cells.emplace_back(Cell(1, 3, 'T'));
        } else if (position == 2) {
            Cells.clear();
            Cells.emplace_back(Cell(1, 2, 'T'));
            Cells.emplace_back(Cell(1, 3, 'T'));
            Cells.emplace_back(Cell(1, 1, 'T'));
            Cells.emplace_back(Cell(0, 2, 'T'));
        } else if (position == 3) {
            Cells.clear();
            Cells.emplace_back(Cell(0, 3, 'T'));
            Cells.emplace_back(Cell(1, 3, 'T'));
            Cells.emplace_back(Cell(2, 3, 'T'));
            Cells.emplace_back(Cell(1, 2, 'T'));
        } else {
            Cells.clear();
            Cells.emplace_back(Cell(0, 1, 'T'));
            Cells.emplace_back(Cell(0, 2, 'T'));
            Cells.emplace_back(Cell(0, 3, 'T'));
            Cells.emplace_back(Cell(1, 2, 'T'));
        }
    } else if (type == '*') {
            Cells.clear();
            Cells.emplace_back(Cell(0, 3, '*'));
    }


}

bool Block::isEmpty() {
    return true; //!TEMPORARY
}

void Block::moveLeft() {
    x++;
}

void Block::moveRight() {
    x--;
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


int Block::isBlockAlive() { // should be in Block.h/cc
    	int length = this->Cells.size();
	for (int i = 0; i < length; ++i) {
	if (this->Cells[i].getLetter())
            return -1;    // returns -1 if one of the cells has a letter (as -1 + 1 = 0)
    }
    return this->levelCreated;
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
