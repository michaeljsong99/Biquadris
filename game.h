//
// Created by Oscar Ding on 2018-11-28.
//

#ifndef PROJECT_GAME_H
#define PROJECT_GAME_H


#include "board.h"
#include "block.h"
#include <string>

class Game {
private:
    std::shared_ptr<AbstractBoard> board1;                   //Board 1
    std::shared_ptr<AbstractBoard> board2;                   //Board 2

    //!!!Maybe this should be handled stored in the command interpreter instead
    std::string fileName;           //Name of file for preset sequences of blocks for level 3/4 (random/norandom)

    int turn;                       //Stores which turn it is.
    int isRandom;                   //For level 3/4, there is an feature to enable/disable random block generation
    std::shared_ptr<Block> currentBlock1;            //Current block for Board 1
    std::shared_ptr<Block> nextBlock1;               //Next block for Board 1
    std::shared_ptr<Block> currentBlock2;            //Current block for Board 2
    std::shared_ptr<Block> nextBlock2;               //Next block for Board 2
public:
    void generateBlock();           //Generates a block. Changes based on level and custom file

    void replaceBlock(char blockType, int board, int block);
                                    //Forcibly changes the current block.
                                    //Make sure to get the x and y of the current block and put it in the new one.

    void resetBoard(int board);     //Resets the Board given the board #

    bool moveBlock(char dir);       //Move the current block on the current player's turn. Returns true if success.

    bool rotateBlock(char dir);     //Rotates the current block on the current player's turn. Returns true if success.

    void drop();                    //Drops the current block on the current player's turn

    void changeLevel(int change, int board);    //Modify the level by change levels e.g change = -2 level 4->2

    void endTurn();                 //Switches turns, generates new blocks, etc
};


#endif //PROJECT_GAME_H
