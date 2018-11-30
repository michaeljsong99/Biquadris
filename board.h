
#ifndef BOARD_H
#define BOARD_H


#include "abstractBoard.h"
#include <vector>
#include <string>
#include "block.h"

class Board : public AbstractBoard{

private:

    int level;                              //Level of the current board

    int score;                              //Score of the current board

    std::vector<Block> Blocks;                    //Stores the blocks
    
    std::vector<vector<Cell>> Grid;               //Stores the grid

    void calculateScore() override;          //Checks for empty blocks and other score sources

    void clearRow() override;

    void update() override;                  //Called after the end of a turn, calls clearRow and calculateScore

public:

    void drop() override;

    bool moveLeft(std::shared_ptr<Block> b) override;          //Returns true if the block doesn't collide

    bool moveRight(std::shared_ptr<Block> b) override;

    bool moveDown(std::shared_ptr<Block> b) override;

    bool rotateCW(std::shared_ptr<Block> b) override;      //Returns true if the block doesn't collide

    bool rotateCCW(std::shared_ptr<Block> b) override;

    void reset() override;                  //Resets the board

    std::string outputBoard() override;                  //Prints board as a string

    void changeLevel(int change) override;             //Modify the level by change levels e.g change = -2 level 4->2

    int getLevel() override;                //Returns current Level

    int getScore() override;;                 //Returns current Level



};


#endif //BOARD_H
