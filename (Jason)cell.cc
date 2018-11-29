#include "cell.h"
using namespace std;

string Cell::getLetter() {
  return letter;
}

void Cell::setLetter(string alphabet) {
  letter = alphabet;
}

int Cell::getX() {
  return x;
}

int Cell::getY() {
  return y;
}

void Cell::setX(int n) {
   x = n;
}

void Cell::setY(int m) {
   y = m;
}
