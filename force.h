#ifndef FORCE_H
#define FORCE_H


#include "decorator.h"

class Force: public Decorator {
private:

    char type;

public:

    Force(std::shared_ptr<AbstractBoard> ab, char type);

};


#endif //FORCE_H
