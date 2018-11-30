#ifndef _CELL_H
#define _CELL_H
#include <string>
#include <iostream>
class Cell {
  int x;
  int y;
  std::string letter;
  bool status = true;
 public:
  friend std::ostream& operator<<(std::ostream &out, Cell &c);
  Cell(int x, int y, string letter);
  std::string getLetter();
  void setLetter(std::string alphabet);
  void setX(int n);
  void setY(int m);
  int getX();
  int getY();
  bool getStatus();
  void setStatus(bool s);
};
#endif
