//
// Created by Oscar Ding on 2018-11-28.
//

#ifndef PROJECT_GAME_H
#define PROJECT_GAME_H


#include "board.h"
#include "block.h"
#include "abstractBoard.h"
#include <memory>
#include <string>
#include <vector>
class Game {
private:
    std::shared_ptr<AbstractBoard> board1;                   //Board 1
    std::shared_ptr<AbstractBoard> board2;                   //Board 2

    //!!!Maybe this should be handled stored in the command interpreter instead
    std::string file; //random/norandom file in level 3 and level 4
    std::string fileName1;           //Name of file for present sequences of blocks for the player1 with level 0 
    std::string fileName2;          // Name of file for present sequences of blocks for the player2 with level 0
    std::vector<char> blockNames1;      //Store the blockNames inside the file.
    std::vector<char> blockNames2;
    int index = 0;                      // Store the index of the block name;
    int turn;                       //Stores which turn it is.
    int isRandom;                   //For level 3/4, there is an feature to enable/disable random block generation
    std::shared_ptr<Block> currentBlock1;            //Current block for Board 1
    std::shared_ptr<Block> nextBlock1;               //Next block for Board 1
    std::shared_ptr<Block> currentBlock2;            //Current block for Board 2
    std::shared_ptr<Block> nextBlock2;               //Next block for Board 2
public:
    void generateBlock(int board);           //Generates a block. Changes based on level and custom file

    void replaceBlock(char blockType, int block);
                                    //Forcibly changes the current block.
                                    //Make sure to get the x and y of the current block and put it in the new one.

    void resetBoard(int board);     //Resets the Board given the board #

    bool moveBlock(char dir, int board);       //Move the current block on the current player's turn. Returns true if success.

    bool rotateBlock(char dir, int board);     //Rotates the current block on the current player's turn. Returns true if success.

    void drop(int board);                    //Drops the current block on the current player's turn

    void changeLevel(int change, int board);    //Modify the level by change levels e.g change = -2 level 4->2

    void endTurn();                 //Switches turns, generates new blocks, etc
    
    void setFilename1(string fn); // set the filename for the player1
    
    void setFilename2(string fn); // set the filename for the player2
    
    void setLevel(int level); // set the level for two boards
};


#endif //PROJECT_GAME_H
