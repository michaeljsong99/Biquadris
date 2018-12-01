
#include "decorator.h"
#include <memory>
using namespace std;
// implementation of the constructor
Decorator::Decorator(AbstractBoard *ab): component{ab} {};

Decorator::~Decorator() {
   delete component;
}

bool Decorator::moveLeft(shared_ptr<Block> b) {
   return component.moveLeft(b);
}

bool Decorator::moveRight(shared_ptr<Block> b) {
   return component.moveRight(b);
}

bool Decorator::moveDown(shared_ptr<Block> b) {
   return component.moveDown(b);
}

bool Decorator::rotateCW(shared_ptr<Block> b) {
   return component.rotateCW(b);
}

bool Decorator::rotateCCW(shared_ptr<Block> b) {
   return component.rotateCCW(b);
}

void Decorator::reset() {
   return component.reset();
}

int Decorator::getLevel() {
   return component.getLevel();
}

int Decorator::getScore() {
   return component.getScore();
}

string Decorator::outputBoard() {
   return component.outputBoard();
}

void Decorator::drop() {
   component.drop();
}
