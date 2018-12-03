#ifndef BLOCK_H
#define BLOCK_H

#include <string>
#include <iostream>
#include <vector>
#include "cell.h"
#include <memory>
#include "window.h"


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

    void moveLeft(int n);    //Moves the cell

    void moveRight(int n);

    void moveDown(int n);

    void rotateCW(int n);    //Rotates the block

    void rotateCCW(int n);

    std::string printBlock() const;

    void drawBlock(int baseX, int baseY, int side ,Xwindow *xw) const;

    void getPos() const;

    int getX() const;

    int getY() const;

    char getLetter() const;

    void setX(int x);

    void setY(int y);

    friend std::ostream& operator<<(std::ostream &out, const Block &b);

};

std::ostream& operator<<(std::ostream &out, const Block &b);

#endif //BLOCK_H
