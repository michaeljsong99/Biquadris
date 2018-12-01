
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
	
	
    bool moveRight(std::shared_ptr<Block> b) override {
    	if (Heavy->moveRight(b)) {	// if it is possible to move the block right
	 	 b->moveRight();		// move the block right
		 for (int i = 0; i < heavy; ++i) {	// does the heaviness feature first
		 	if (Heavy->moveDown(b)) {
				b->moveDown();
			}
			else {
				Heavy->drop();	//ends the turn as it cannot move down further
				return true;	//returns true as the right move is allowed.
			}
		 }
	 	 if (Heavy->moveDown(b) && Heavy->moveDown2(b)) {	// checks if can move down 1 and 2 rows.
			 b->moveDown();
			 b->moveDown();
			 return true;
		 }
		 else {
		 	Heavy->drop(); // ends the turn as it is not possible to drop 2 rows
			return true;   // returns true as the right move is allowed.
		 }
	 }
	return false;	// returns false if the right move is not legal.
    }

    bool moveDown(std::shared_ptr<Block> b) override {
	 if (Heavy->moveDown(b)) {	// if it is possible to move the block down
	 	 b->moveDown();		// move the block down
		 for (int i = 0; i < heavy; ++i) {	// does the heaviness feature first
		 	if (Heavy->moveDown(b)) {
				b->moveDown();
			}
			else {
				Heavy->drop();	//ends the turn as it cannot move down further
				return true;	//returns true as the down move is allowed.
			}
		 }
	 	 if (Heavy->moveDown(b) && Heavy->moveDown2(b)) {	// checks if can move down 1 and 2 rows.
			 b->moveDown();
			 b->moveDown();
			 return true;
		 }
		 else {
		 	Heavy->drop(); // ends the turn as it is not possible to drop 2 rows
			return true;   // returns true as the down move is allowed.
		 }
	 }
	return false;	// returns false if the down move is not legal.
    }

    bool rotateCW(std::shared_ptr<Block> b) override {      //Returns true if the block doesn't collide
	if (Heavy->rotateCW(b)) {	// if it is possible to rotate CW
	 	 b->rotateCW();		// rotate CW
		 for (int i = 0; i < heavy; ++i) {	// does the heaviness feature first
		 	if (Heavy->moveDown(b)) {
				b->moveDown();
			}
			else {
				Heavy->drop();	//ends the turn as it cannot move down further
				return true;	//returns true as the rotate CW move is allowed.
			}
		 }
	 	 if (Heavy->moveDown(b) && Heavy->moveDown2(b)) {	// checks if can move down 1 and 2 rows.
			 b->moveDown();
			 b->moveDown();
			 return true;
		 }
		 else {
		 	Heavy->drop(); // ends the turn as it is not possible to drop 2 rows
			return true;   // returns true as the rotate CW move is allowed.
		 }
	 }
	return false;	// returns false if the rotate CW move is not legal.
    }
	
    bool rotateCCW(std::shared_ptr<Block> b) override {		//Returns true if the block doesn't collide
	if (Heavy->rotateCCW(b)) {	// if it is possible to rotate CCW
	 	 b->rotateCCW();		// rotates CCW
		 for (int i = 0; i < heavy; ++i) {	// does the heaviness feature first
		 	if (Heavy->moveDown(b)) {
				b->moveDown();
			}
			else {
				Heavy->drop();	//ends the turn as it cannot move down further
				return true;	//returns true as the rotate CCW move is allowed.
			}
		 }
	 	 if (Heavy->moveDown(b) && Heavy->moveDown2(b)) {	// checks if can move down 1 and 2 rows.
			 b->moveDown();
			 b->moveDown();
			 return true;
		 }
		 else {
		 	Heavy->drop(); // ends the turn as it is not possible to drop 2 rows
			return true;   // returns true as the rotate CCW move is allowed.
		 }
	 }
	return false;	// returns false if the down move is not legal.
    }
};
