
#ifndef CELL_H
#define CELL_H

#include <iostream>

class Cell {
private:

    int x, y;               //Coordinates

    char letter;            //Symbol

public:
    char getSymbol();       //Returns the Symbol

    int getX();             //Returns Coords

    int getY();
};

std::ostream &::operator<<(std::ostream &out, const Cell &c);

#endif //CELL_H

