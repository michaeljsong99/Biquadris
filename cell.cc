
#include "cell.h"
using namespace std;

Cell::Cell(int x, int y, char letter): x{x}, y{y}, letter{letter} {}


char Cell::getLetter() const {
    return letter;
}

int Cell::getX() const{
    return x;
}

int Cell::getY() const{
    return y;
}

void Cell::setLetter(char letter) {
    this->letter = letter;
}

void Cell::setX(int x) {
    this->x = x;
}

void Cell::setY(int y) {
    this->y = y;
}

ostream& operator<<(ostream &out, const Cell &c) {
    return out << c.getLetter();
}

