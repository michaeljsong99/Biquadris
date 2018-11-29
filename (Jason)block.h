#ifndef _BLOCK_H
#define _BLOCK_H
#include "cell.h"
#include <vector>

class Block {
  std::string name; // name of the block
  <vector <vector Cell>> container;
  int container_width;
  int container_height;
  int levelCreated;
 public:
  int getWidth();
  int getHeight();
  void setWidth();
  void setHeight();
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
