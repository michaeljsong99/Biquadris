#ifndef BLIND_H
#define BLIND_H

#include "decorator.h"

class Blind : public Decorator {

public:

    Blind(std::shared_ptr<AbstractBoard> ab);

    std::string printBoard() const override;                  //Override with ??

};


#endif //BLIND_H
