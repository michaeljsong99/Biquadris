#ifndef _BLOCK_H
#define _BLOCK_H
#include "cell.h"
#include <vector>
#include <iostream>

class Block {
  std::string name; // name of the block
  std::vector<std::vector<Cell>> container;
  int container_width;
  int container_height;
  int levelCreated;
 public:
  friend std::ostream& operator<<(std::ostream &out, Block &b);
  int getWidth();
  int getHeight();
  void setWidth(int width);
  void setHeight(int height);
  void setBlock();
  void moveLeft();
  void moveRight();
  void moveDown();
  void rotateCW();
  void rotateCCW();
  void getScore();
  Block(std::string name, int levelCreated);
};
#endif
