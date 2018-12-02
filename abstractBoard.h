#ifndef ABSTRACTBOARD_H
#define ABSTRACTBOARD_H

#include <string>
#include <vector>
#include "block.h"

class AbstractBoard {
public:

    virtual ~AbstractBoard();

    virtual void setCurrentBlock(std::shared_ptr<Block> b) = 0;

    virtual void setNextBlock(std::shared_ptr<Block> b) = 0;

    virtual void addBlock(std::shared_ptr<Block> b) = 0;

    virtual void drawCurrentBlock() = 0;

    virtual bool canMoveLeft(int n) = 0;         //Returns true if the block doesn't collide

    virtual bool canMoveRight(int n) = 0;

    virtual bool canMoveDown(int n) = 0;

    virtual bool canRotateCW(int n) = 0;      //Returns true if the block doesn't collide

    virtual bool canRotateCCW(int n) = 0;

    virtual void drop() = 0;

    virtual void reset() = 0;                  //Resets the board

    virtual void updateGrid() = 0;

    virtual int getScore() = 0;                 //Returns current score

    virtual int getLevel() = 0;                 //Returns current level

    virtual void changeLevel(int change) = 0;              //Modify the level by change levels e.g change = -2 level 4->2

    virtual std::string printBoard() const = 0;                  //Prints board as a string

};

std::ostream& operator<<(std::ostream &out, const AbstractBoard &b);

#endif //ABSTRACTBOARD_H
