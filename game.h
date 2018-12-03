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
#include <fstream>
class Game {
private:

    int index = 0;                      // Store the index of the block name;

    int board;                       //Stores which turn it is.

    bool isRandom;                   //For level 3/4, there is an feature to enable/disable random block generation

    bool graphics = true;

    std::shared_ptr<AbstractBoard> b1;                   //Board 1

    std::shared_ptr<AbstractBoard> b2;                   //Board 2

    std::ifstream f1;           //Name of file for present sequences of blocks for the player1 with level 0

    std::ifstream f2;          // Name of file for present sequences of blocks for the player2 with level 0

    std::vector<char> blockNames1;      //Store the blockNames inside the file.

    std::vector<char> blockNames2;

    std::shared_ptr<Block> cBlock1;            //Current block for Board 1

    std::shared_ptr<Block> nBlock1;               //Next block for Board 1

    std::shared_ptr<Block> cBlock2;            //Current block for Board 2

    std::shared_ptr<Block> nBlock2;               //Next block for Board 2

    std::shared_ptr<Block> e;

public:
    Game();

    void init();                        //Initializes the game

    std::shared_ptr<Block> generateBlock(int board);           //Generates a block. Changes based on level and custom file

    void replaceBlock(char blockType, int board);
                                    //Forcibly changes the current block.
                                    //Make sure to get the x and y of the current block and put it in the new one.

    void resetBoard(int board);     //Resets the Board given the board #

    bool moveBlock(char dir, int board, int n);       //Move the current block on the current player's turn. Returns true if success.

    bool rotateBlock(char dir, int board, int n);     //Rotates the current block on the current player's turn. Returns true if success.

    void drop(int board);                    //Drops the current block on the current player's turn

    void changeLevel(int change, int board);    //Modify the level by change levels e.g change = -2 level 4->2

    void endTurn(int board);                 //Switches turns, generates new blocks, etc
    
    void setFile1(std::string fn); // set the filename for the player1
    
    void setFile2(std::string fn); // set the filename for the player2
    
    void setLevel(int level); // set the level for two boards

    void setGraphics(bool b);

    std::string printGame() const;

};

std::ostream& operator<<(std::ostream &out, const Game &g);


#endif //PROJECT_GAME_H
