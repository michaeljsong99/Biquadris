#ifndef BLIND_H
#define BLIND_H

#include "decorator.h"

class Blind : public Decorator {

public:

    Blind(std::shared_ptr<AbstractBoard> ab);

    std::string printBoard() const override;                  //Override with ??

    void drawBoard(int baseX, int baseY) const override;

};


#endif //BLIND_H
