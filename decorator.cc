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

bool Decorator::moveRight(int n) {
   return component->moveRight(n);
}

bool Decorator::moveLeft(int n) {
   return component->moveLeft(n);
}

bool Decorator::moveDown(int n) {
   return component->moveDown(n);
}

bool Decorator::rotateCW(int n) {
   return component->rotateCW(n);
}

bool Decorator::rotateCCW(int n) {
   return component->rotateCCW(n);
}

bool Decorator::shiftDown() {
   return component->shiftDown();
}

void Decorator::drop() {
   return component->drop();
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

void Decorator::setLevel(int n) {
   component->setLevel(n);
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

void Decorator::setHeavy(int n) {
      component->setHeavy(n);
}

bool Decorator::isGameOver() {
    return component->isGameOver();
}

bool Decorator::getDropped() {
   return component->getDropped();
}

void Decorator::setDropped(bool b) {
   component->setDropped(b);
}

int Decorator::getRowsCleared() {
   return component->getRowsCleared();
}

void Decorator::dropMiddle() {
   component->dropMiddle();
}

void Decorator::drawBoard(int baseX, int baseY) const {
    component->drawBoard(baseX, baseY);
}

Xwindow *Decorator::getXW() const {
    return component->getXW();
}



