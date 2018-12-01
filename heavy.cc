
#include "heavy.h"

class Heavy: public Decorator {
private:
    int heavy;

public:

    Heavy(std::shared_ptr<AbstractBoard> ab);
    // Every time a block moves left or right, it automatically falls by two rows, after the horizontal move.
    // If it is not possible for the block to drop two rows, it is considered to be dropped, and the turn ends.
    // If the player is in a level where the blocks are heavy, the effect is cumulative (the player suffers from both effects).
  
    bool moveLeft(std::shared_ptr<Block> b) override;           //Returns true if the block doesn't collide
         if
    bool moveRight(std::shared_ptr<Block> b) override;

    bool moveDown(std::shared_ptr<Block> b) override;

    bool rotateCW(std::shared_ptr<Block> b) override;      //Returns true if the block doesn't collide

    bool rotateCCW(std::shared_ptr<Block> b) override;    //Returns true if the block doesn't collide

};



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

