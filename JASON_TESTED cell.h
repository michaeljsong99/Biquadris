#ifndef _CELL_H
#define _CELL_H
#include <string>
#include <iostream>
class Cell {
  int x;
  int y;
  std::string letter;
 public:
  friend std::ostream& operator<<(std::ostream &out, Cell &c);
  std::string getLetter();
  void setLetter(std::string alphabet);
  void setX(int n);
  void setY(int m);
  int getX();
  int getY();
};
#endif
