
#ifndef BLOCK_H
#define BLOCK_H

#include <iostream>
#include <vector>
#include "cell.h"


class Block {
private:
    //!Or Enum whatever you guys wanna do
    char type;       //Stores the type of block

    int position;   //Stores it's current rotated position (1,2,3,4)

    int x, y;       //Coordinates for the Bottom Left Corner

    int levelCreated;   //Stores the level the block was generated in
    //!Technically we don't even really need the cell class
    std::vector<Cell> Cells;  //Vector of Cells

    void setBlock();     //Resets Cells

    std::vector<std::vector<Cell>> Grid;        //Temp for out

public:

    Block(char type, int position);

    bool isEmpty();     //Checks if the cells are all cleared

    void moveLeft();    //Moves the cell

    void moveRight();

    void moveDown();

    void rotateCW();    //Rotates the block

    void rotateCCW();

    void printBlock();

    void getPos();

    int getX();

    int getY();

    void setX(int x);

    void setY(int y);

    friend std::ostream& ::operator<<(std::ostream &out, const Block &b);

};


#endif //BLOCK_H
