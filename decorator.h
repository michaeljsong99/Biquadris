#ifndef DECORATOR_H
#define DECORATOR_H

#include "abstractBoard.h"

class Decorator: public AbstractBoard {
protected:

    std::shared_ptr<AbstractBoard> component;           //nested ab

    int id;

public:

    Decorator(std::shared_ptr<AbstractBoard> ab);       //ctor

    void setCurrentBlock(std::shared_ptr<Block> b) override;

    void setNextBlock(std::shared_ptr<Block> b) override;

    void addBlock(std::shared_ptr<Block> b) override;

    void drawCurrentBlock() override;

    bool canMoveLeft(int n) override;         //Returns true if the block doesn't collide

    bool canMoveRight(int n) override;

    bool canMoveDown(int n) override;

    bool canRotateCW(int n) override;      //Returns true if the block doesn't collide

    bool canRotateCCW(int n) override;

    bool moveRight(int n) override;

    bool moveLeft(int n) override;

    bool moveDown(int n) override;

    bool rotateCW(int n) override;

    bool rotateCCW(int n) override;

    bool shiftDown() override;

    void drop() override;

    void reset() override;                  //Resets the board

    void updateGrid() override;

    int getScore() override;                 //Returns current score

    int getLevel() override;                 //Returns current level

    void setLevel(int n) override;

    void changeLevel(int change) override;              //Modify the level by change levels e.g change = -2 level 4->2

    bool isGameOver() override;

    std::string printBoard() const override;                  //Prints board as a string

    void drawBoard(int baseX, int baseY) const override;

    Xwindow* getXW() const override;

    std::shared_ptr<AbstractBoard> removeDecorator() override;

    void setHeavy(int n) override;

    bool getDropped() override;

    void setDropped(bool b) override;

    int getRowsCleared() override;

    void dropMiddle() override;


};


#endif //DECORATOR_H
