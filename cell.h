
#ifndef CELL_H
#define CELL_H

#include <iostream>

class Cell {
private:

    int x, y;               //Coordinates

    char letter;            //Symbol

public:
    Cell(int x, int y, char letter);

    char getLetter() const;       //Returns the Symbol

    int getX();             //Returns Coords

    int getY();

    void setLetter(char letter);

    void setX(int x);

    void setY(int y);

    friend std::ostream& operator<<(std::ostream &out, const Cell &c);
};


#endif //CELL_H