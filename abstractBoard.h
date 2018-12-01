
#ifndef ABSTRACTBOARD_H
#define ABSTRACTBOARD_H


#include <string>
#include <vector>
#include "block.h"

class AbstractBoard {
private:

    virtual void calculateScore();          //Checks for empty blocks and other score sources

    virtual void clearRow();

    virtual void update();                  //Called after the end of a turn, calls clearRow and calculateScore

public:

    virtual ~AbstractBoard() = 0;

    virtual void drop() = 0;

    virtual bool moveLeft(std::shared_ptr<Block> b) = 0;           //Returns true if the block doesn't collide

    virtual bool moveRight(std::shared_ptr<Block> b) = 0;

    virtual bool moveDown(std::shared_ptr<Block> b) = 0;

    virtual bool rotateCW(std::shared_ptr<Block> b) = 0;      //Returns true if the block doesn't collide

    virtual bool rotateCCW(std::shared_ptr<Block> b) = 0;

    virtual void reset() = 0;                  //Resets the board

    virtual std::string outputBoard() = 0;                  //Prints board as a string

    virtual void changeLevel(int change) = 0;              //Modify the level by change levels e.g change = -2 level 4->2

    virtual int getLevel() = 0;                 //Returns current Level

    virtual int getScore() = 0;                 //Returns current Level



};

std::ostream& ::operator<<(std::ostream &out, const AbstractBoard &b);

#endif //ABSTRACTBOARD_H
