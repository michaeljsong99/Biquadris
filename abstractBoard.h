#ifndef ABSTRACTBOARD_H
#define ABSTRACTBOARD_H

#include <string>
#include <vector>
#include "block.h"
#include <memory>

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

    virtual bool moveRight(int n) = 0;

    virtual bool moveLeft(int n) = 0;

    virtual bool moveDown(int n) = 0;

    virtual bool rotateCW(int n) = 0;

    virtual bool rotateCCW(int n) = 0;

    virtual bool shiftDown() = 0;

    virtual void drop() = 0;

    virtual void reset() = 0;                  //Resets the board

    virtual void updateGrid() = 0;

    virtual int getScore() = 0;                 //Returns current score

    virtual int getLevel() = 0;                 //Returns current level

    virtual void setLevel(int n) = 0;

    virtual void changeLevel(int change) = 0;              //Modify the level by change levels e.g change = -2 level 4->2

    virtual bool isGameOver() = 0;

    virtual std::string printBoard() const = 0;                  //Prints board as a string

    virtual void drawBoard(int baseX, int baseY) const =0;

    virtual Xwindow* getXW() const = 0;

    virtual void setHeavy(int n) = 0;

    virtual bool getDropped() = 0;

    virtual void setDropped(bool b) = 0;

    virtual int getRowsCleared() = 0;

    virtual void dropMiddle() = 0;

    virtual std::shared_ptr<AbstractBoard> removeDecorator() = 0;

};

std::ostream& operator<<(std::ostream &out, const AbstractBoard &b);

#endif //ABSTRACTBOARD_H
