
#include "heavy.h"

class Heavy: public Decorator {
private:
    int heavy;

public:

    Heavy(std::shared_ptr<AbstractBoard> ab);
    // Every time a block moves left or right, it automatically falls by two rows, after the horizontal move.
    // If it is not possible for the block to drop two rows, it is considered to be dropped, and the turn ends.
    // If the player is in a level where the blocks are heavy, the effect is cumulative (the player suffers from both effects).
  
    // Note: My functions move the blocks in addition to returning a boolean value.
	
    bool moveLeft(std::shared_ptr<Block> b) override {           //Returns true if the block doesn't collide
         if (Heavy->moveLeft(b)) {	// if it is possible to move the block left
	 	 b->moveLeft();		// move the block left
		 for (int i = 0; i < heavy; ++i) {	// does the heaviness feature first
		 	if (Heavy->moveDown(b)) {
				b->moveDown();
			}
			else {
				Heavy->drop();	//ends the turn as it cannot move down further
				return true;	//returns true as the left move is allowed.
			}
		 }
	 	 if (Heavy->moveDown(b) && Heavy->moveDown2(b)) {	// checks if can move down 1 and 2 rows.
			 b->moveDown();
			 b->moveDown();
			 return true;
		 }
		 else {
		 	Heavy->drop(); // ends the turn as it is not possible to drop 2 rows
			return true;   // returns true as the left move is allowed.
		 }
	 }
	return false;	// returns false if the left move is not legal.
    }
	
	
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

public:

    Block(char type, int position, int levelCreated);

    bool isEmpty();     //Checks if the cells are all cleared

    void moveLeft();    //Moves the cell

    void moveRight();

    void moveDown();

    void rotateCW();    //Rotates the block

    void rotateCCW();

    void printBlock();

    void getPos();

