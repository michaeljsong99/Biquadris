#ifndef BLIND_H
#define BLIND_H

#include "decorator.h"

class Blind : public Decorator {

    std::shared_ptr<AbstractBoard> component;           //nested ab

public:

    Blind(std::shared_ptr<AbstractBoard> ab);

    std::string printBoard();                  //Override with ??

};


#endif //BLIND_H
