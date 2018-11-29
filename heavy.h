

#ifndef HEAVY_H
#define HEAVY_H


#include "decorator.h"

class Heavy: public Decorator {
private:
    int heavy;

public:

    Heavy(std::shared_ptr<AbstractBoard> ab);

    bool moveLeft(std::shared_ptr<Block> b) override;           //Returns true if the block doesn't collide

    bool moveRight(std::shared_ptr<Block> b) override;

    bool moveDown(std::shared_ptr<Block> b) override;

    bool rotateCW(std::shared_ptr<Block> b) override;      //Returns true if the block doesn't collide

    bool rotateCCW(std::shared_ptr<Block> b) override;    //Returns true if the block doesn't collide

};


#endif //HEAVY_H
