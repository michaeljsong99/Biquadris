
#include "block.h"
using namespace std;

Block::Block(char type, int position) :type{type}, position{position} {
    setBlock();
}

void Block::setBlock() {
    if (type == 'I') {
        if (position == 1 || position == 3) {
            Cells.clear();
            Cells.push_back(Cell(0, 0, 'I'));
            Cells.push_back(Cell(0, 1, 'I'));
            Cells.push_back(Cell(0, 2, 'I'));
            Cells.push_back(Cell(0, 3, 'I'));
        } else {
            Cells.clear();
            Cells.push_back(Cell(0, 0, 'I'));
            Cells.push_back(Cell(1, 0, 'I'));
            Cells.push_back(Cell(2, 0, 'I'));
            Cells.push_back(Cell(3, 0, 'I'));
        }
    }
    if (type == 'J') {

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
