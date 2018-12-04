
#ifndef BOARD_H
#define BOARD_H

#include "abstractBoard.h"
#include <memory>
#include <vector>
#include <string>
#include "block.h"
#include "window.h"

class Block;

class Board: public AbstractBoard {

private:

    char filler = ' ';                          //Filler character for empty

    int level = 0;                              //Level of the current board

    int score = 0;                              //Score of the current board

    int hiscore = 0;

    int width = 10;

    int height = 17;

    bool dropped = false;

    int rowsCleared = 0;

    int side = 20;

    Xwindow* xw;

    std::shared_ptr<Block> cBlock;          //Current Block

    std::shared_ptr<Block> nBlock;          //Current Block

    std::vector<std::shared_ptr<Block>> Blocks;                    //Stores the blocks

    std::vector<std::vector<Cell>> Grid;

    void endTurn();

    void calculateScore(int rows);

    int clearRows();

    void clearRow(int row);

public:

    Board(Xwindow *xw);

    void setCurrentBlock(std::shared_ptr<Block> b) override;

    void setNextBlock(std::shared_ptr<Block> b) override;

    void addBlock(std::shared_ptr<Block> b) override;

    void drawCurrentBlock() override;

    bool canMoveLeft(int n) override;

    bool canMoveRight(int n) override;

    bool canMoveDown(int n) override;

    bool canRotateCW(int n) override;     //Returns true if the block doesn't collide

    bool canRotateCCW(int n) override;

    bool moveRight(int n) override;

    bool moveLeft(int n) override;

    bool moveDown(int n) override;

    bool rotateCW(int n) override;

    bool rotateCCW(int n) override;

    bool shiftDown() override;

    void drop() override;

    void reset() override;

    void updateGrid() override;

    int getScore() override;

    int getLevel() override;

    void setLevel(int n) override;

    void changeLevel(int change) override;

    bool isGameOver() override;

    void setHeavy(int n) override;

    bool getDropped() override;

    void setDropped(bool b) override;

    int getRowsCleared() override;

    std::shared_ptr<AbstractBoard> removeDecorator() override;

    void dropMiddle() override;

    std::string printBoard() const override;

    void drawBoard(int baseX, int baseY) const override;

    Xwindow* getXW() const override;

};

//std::ostream& operator<<(std::ostream &out, const Board &b);


#endif //BOARD_H
