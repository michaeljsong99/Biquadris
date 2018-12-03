#ifndef HEAVY_H
#define HEAVY_H


#include "decorator.h"

class Heavy: public Decorator {
private:
    
    int heavy;

    bool isSA;

public:

    Heavy(std::shared_ptr<AbstractBoard> ab, int heavy, bool isSA);

    bool moveLeft(int n) override;           //Returns true if the block doesn't collide

    bool moveRight(int n) override;

    bool moveDown(int n) override;

    bool rotateCW(int n) override;      //Returns true if the block doesn't collide

    bool rotateCCW(int n) override;    //Returns true if the block doesn't collide

    void setHeavy(int n) override;
};


#endif //HEAVY_H
