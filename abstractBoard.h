
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

    virtual ~AbstractBoard();

    virtual void drop();

    virtual bool moveLeft(std::shared_ptr<Block> b);           //Returns true if the block doesn't collide

    virtual bool moveRight(std::shared_ptr<Block> b);

    virtual bool moveDown(std::shared_ptr<Block> b);

    virtual bool rotateCW(std::shared_ptr<Block> b);      //Returns true if the block doesn't collide

    virtual bool rotateCCW(std::shared_ptr<Block> b);

    virtual void reset();                  //Resets the board

    virtual std::string outputBoard();                  //Prints board as a string

    virtual void changeLevel(int change);              //Modify the level by change levels e.g change = -2 level 4->2

    virtual int getLevel();                 //Returns current Level

    virtual int getScore();                 //Returns current Level



};

std::ostream& ::operator<<(std::ostream &out, const AbstractBoard &b);

#endif //ABSTRACTBOARD_H
