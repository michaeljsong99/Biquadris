
#ifndef BOARD_H
#define BOARD_H

#include "abstractBoard.h"
#include <memory>
#include <vector>
#include <string>
#include "block.h"

class Block;

class Board: public AbstractBoard {

private:

    char filler = '+';                          //Filler character for empty

    int level = 0;                              //Level of the current board

    int score = 0;                              //Score of the current board

    int hiscore = 0;

    int width = 10;

    int height = 17;

    std::shared_ptr<Block> cBlock;          //Current Block

    std::shared_ptr<Block> nBlock;          //Current Block

    std::vector<std::shared_ptr<Block>> Blocks;                    //Stores the blocks

    std::vector<std::vector<Cell>> Grid;

    void endTurn();

    void calculateScore(int rows);

    int clearRows();

    void clearRow(int row);

    bool isGameOver();

    //void insertRows(int rows);

public:

    void setCurrentBlock(std::shared_ptr<Block> b);

    void setNextBlock(std::shared_ptr<Block> b);

    void drawCurrentBlock();

    bool canMoveLeft(int n); //override;

    bool canMoveRight(int n); //override;

    bool canMoveDown(int n); //override;

    bool canRotateCW(int n);      //Returns true if the block doesn't collide

    bool canRotateCCW(int n);

    void drop();

    void addBlock(std::shared_ptr<Block> block);

    void updateGrid();

    void changeLevel(int change);

    int getLevel();

    std::string printBoard() const;

    friend std::ostream& operator<<(std::ostream &out, const Board &b);

};


#endif //BOARD_H
