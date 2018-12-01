#ifndef BOARD_H
#define BOARD_H


//#include "abstractBoard.h"
#include <vector>
#include <string>
#include "block.h"
#include "cell.h"

class Board {//: public AbstractBoard{

private:
    std::vector<std::vector<Cell>> BoardGrid;

    int level;                              //Level of the current board

    int score;                              //Score of the current board
    
    int hi_score;


    std::vector<std::shared_ptr<Block>> Blocks;                    //Stores the blocks

    std::vector<std::vector<Cell>> Grid;

    void clearRow() override;

    void update() override;                  //Called after the end of a turn, calls clearRow and calculateScore

public:

    void drop() override;

    bool moveLeft(std::shared_ptr<Block> b) override;          //Returns true if the block doesn't collide                  //Stores the blocks as pointers
    
    bool CanClearOneRow();
    
    int CalculateScore();          //Checks for empty blocks and other score sources


    int ClearRows();

    void update();                  //Called after the end of a turn, calls clearRow and calculateScore
	



    bool rotateCCW(std::shared_ptr<Block> b) override;

    void reset() override;                  //Resets the board

    std::string outputBoard() override;                  //Prints board as a string

    void changeLevel(int change) override;             //Modify the level by change levels e.g change = -2 level 4->2

    int getLevel() override;                //Returns current Level

    int getScore() override;                //Returns current Level


    void updateGrid();

};

#endif //BOARD_H
