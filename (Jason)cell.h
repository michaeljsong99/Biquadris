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

std::ostream& ::operator<<(std::ostream &out, const Cell &c);

#endif
