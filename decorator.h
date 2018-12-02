#ifndef DECORATOR_H
#define DECORATOR_H

#include "abstractBoard.h"

class Decorator: public AbstractBoard {
protected:

    std::shared_ptr<AbstractBoard> component;           //nested ab

public:

    Decorator(std::shared_ptr<AbstractBoard> ab) override;       //ctor

    void setCurrentBlock(std::shared_ptr<Block> b) override;

    void setNextBlock(std::shared_ptr<Block> b) override;

    void addBlock(std::shared_ptr<Block> b) override;

    void drawCurrentBlock() override;

    bool canMoveLeft(int n) override;         //Returns true if the block doesn't collide

    bool canMoveRight(int n) override;

    bool canMoveDown(int n) override;

    bool canRotateCW(int n) override;      //Returns true if the block doesn't collide

    bool canRotateCCW(int n) override;

    void drop() override;

    void reset() override;                  //Resets the board

    void updateGrid() override;

    int getScore() override;                 //Returns current score

    int getLevel() override;                 //Returns current level

    void changeLevel(int change) override;              //Modify the level by change levels e.g change = -2 level 4->2

    std::string printBoard() const override;                  //Prints board as a string

};


#endif //DECORATOR_H
