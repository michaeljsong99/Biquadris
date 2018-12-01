#include "cell.h"
using namespace std;

Cell::Cell(int x, int y, string l): x{x}, y{y}, letter{l}, status{true} {}

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

ostream &operator<<(ostream &out, Cell &c) {
   if (c.letter == "") {
     out << " ";
     return out;
   } 
   out << c.letter;
   return out;
}
bool Cell::getStatus() {
  return status;
}
void Cell::setStatus(bool s) {
  status = s;
}
