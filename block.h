
#ifndef BLOCK_H
#define BLOCK_H

#include <iostream>
#include <vector>
#include "cell.h"

class Board;


class Block {
private:

    char type;       //Stores the type of block

    int position;   //Stores it's current rotated position (1,2,3,4)

    int x, y;     //Coordinates for the Bottom Left Corner

    int levelCreated;   //Stores the level the block was generated in

    std::vector<Cell> Cells;  //Vector of Cells

    void setBlock();     //Resets Cells

    std::vector<std::vector<Cell>> Grid;        //Temp for out

    friend Board;

public:

    Block(char type, int position, int level);

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

    void MoveDown(int row_number);

    friend std::ostream& operator<<(std::ostream &out, const Block &b);

};

std::ostream& operator<<(std::ostream &out, const Block &b);

#endif //BLOCK_H
