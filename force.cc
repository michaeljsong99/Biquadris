#include "force.h"

using namespace std;

Force::Force(std::shared_ptr<AbstractBoard> ab, char type): Decorator{ab} {
    int level = component->getLevel();
    auto nb = make_shared<Block>(type, 1, level);
    component->setCurrentBlock(nb);
}
