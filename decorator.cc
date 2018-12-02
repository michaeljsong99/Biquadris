#include "decorator.h"
#include <memory>

using namespace std;
// implementation of the constructor
Decorator::Decorator(std::shared_ptr<AbstractBoard> ab): component{ab} {};

void Decorator::setCurrentBlock(std::shared_ptr<Block> b) {
   component->setCurrentBlock(b);
}

void Decorator::setNextBlock(std::shared_ptr<Block> b) {
   component->setNextBlock(b);
}

void Decorator::addBlock(std::shared_ptr<Block> b) {
   component->addBlock(b);
}

void Decorator::drawCurrentBlock() {
   component->drawCurrentBlock();
}

bool Decorator::canMoveLeft(int n) {
   return component->canMoveLeft(n);
}

bool Decorator::canMoveRight(int n) {
   return component->canMoveRight(n);
}

bool Decorator::canMoveDown(int n) {
   return component->canMoveDown(n);
}

bool Decorator::canRotateCW(int n) {
   return component->canRotateCW(n);
}

bool Decorator::canRotateCCW(int n) {
   return component->canRotateCCW(n);
}

void Decorator::drop() {
   component->drop();
}

void Decorator::reset() {
   component->reset();
}

void Decorator::updateGrid() {
   component->updateGrid();
}

int Decorator::getScore() {
   return component->getScore();
}

int Decorator::getLevel() {
   return component->getLevel();
}

void Decorator::changeLevel(int change) {
   component->changeLevel(change);
}

std::string Decorator::printBoard() const {
   return component->printBoard();
}

std::shared_ptr<AbstractBoard> Decorator::removeDecorator() {
    return component;
}
