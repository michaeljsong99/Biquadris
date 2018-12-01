
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
        
    bool moveRight(std::shared_ptr<Block> b) override;

    bool moveDown(std::shared_ptr<Block> b) override;

    bool rotateCW(std::shared_ptr<Block> b) override;      //Returns true if the block doesn't collide

    bool rotateCCW(std::shared_ptr<Block> b) override;    //Returns true if the block doesn't collide

};
