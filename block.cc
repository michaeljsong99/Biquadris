
#include "block.h"
#include <sstream>
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

void Block::moveLeft(int n) {
    x -= n;
}

void Block::moveRight(int n) {
    x += n;
}

void Block::moveDown(int n) {
    y += n;
}

void Block::rotateCCW(int n) {
    while (n>0) {
        n--;
        if (position == 1) {
            position = 4;
        } else position--;
    }
    setBlock();
}

void Block::rotateCW(int n) {
    while (n>0) {
        n--;
        if (position == 4) {
            position = 1;
        } else position++;
    }
    setBlock();
}

string Block::printBlock() const{
    ostringstream oss;

    int maxX = 10;
    int maxY = 1;


    for (int y = maxY; y >= 0; y--) {
        for (int x = 0; x <= maxX; x++) {
            int flag = 0;
            for(auto & c : Cells) {
                if (c.getX() == x && c.getY() == y) {
                    oss << c.getLetter();
                    flag = 1;
                }

            }
            if(flag == 0) {
                oss << ' ';
            }
        }
        oss << endl;
    }
    return oss.str();
}

void Block::drawBlock(int baseX, int baseY, int side ,Xwindow *xw) const{
    for(auto & c : Cells) {
        int x = c.getX();
        int y = 1 - c.getY();
        char letter = c.getLetter();
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
        }
    }
}

void Block::getPos() const{
    cout << position;
}

int Block::getX() const{
    return x;
}

int Block::getY() const{
    return y;
}

char Block::getLetter() const {
    return type;
}

void Block::setX(int x) {
    this->x = x;
}

void Block::setY(int y) {
    this->y = y;
}

ostream& operator<<(ostream &out, const Block &b) {
    return out << b.printBlock();
}

