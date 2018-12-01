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

    std::vector<Block*> Blocks;                    //Stores the blocks as pointers
    
    bool CanClearOneRow();
    
    int CalculateScore();          //Checks for empty blocks and other score sources

    int ClearRows();

    void update();                  //Called after the end of a turn, calls clearRow and calculateScore
	





};

#endif //BOARD_H
