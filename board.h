
#ifndef BOARD_H
#define BOARD_H

#include "abstractBoard.h"
#include <memory>
#include <vector>
#include <string>
#include "block.h"

class Block;

class Board{//; : public AbstractBoard {

private:

    int level = 0;                              //Level of the current board

    int score = 0;                              //Score of the current board

    int hiscore = 0;

    std::shared_ptr<Block> cBlock;          //Current Block

    std::shared_ptr<Block> nBlock;          //Current Block

    std::vector<std::shared_ptr<Block>> Blocks;                    //Stores the blocks

    std::vector<std::vector<Cell>> Grid;

    void endTurn();

    void calculateScore(int rows);

    int clearRows();

    void clearRow(int row);

    //void insertRows(int rows);

public:

    void setCurrentBlock(std::shared_ptr<Block> b);

    void setNextBlock(std::shared_ptr<Block> b);

    void drawCurrentBlock();

    bool canMoveLeft(); //override;

    bool canMoveRight(); //override;

    bool canMoveDown(); //override;

    bool canRotateCW();      //Returns true if the block doesn't collide

    bool canRotateCCW();

    void drop();

    void addBlock(std::shared_ptr<Block> block);

    void updateGrid();

    void changeLevel(int change);

    int getLevel();

    std::string printBoard() const;

    friend std::ostream& operator<<(std::ostream &out, const Board &b);

};


#endif //BOARD_H
