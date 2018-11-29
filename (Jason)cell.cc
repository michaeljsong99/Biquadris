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

std::ostream& ::operator<<(std::ostream &out, const Cell &c){
    cout << letter;
    return out;
}

/*
#ifndef _CELL_H
#define _CELL_H
#include <string>
class Cell {
  int x;
  int y;
  std::string letter;
 public:
  std::string getLetter();
  void setLetter(std::string alphabet);
  void setX(int n);
  void setY(int m);
  int getX();
  int getY();
};
#endif
*/
