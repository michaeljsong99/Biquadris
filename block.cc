
#include "block.h"

std::ostream& ::operator<<(std::ostream &out, const Block &b){
    for (int i = 0; i < container_height; ++i) {
        for (int j = 0; j < container_width; ++j) {
            cout << container[i][j];
        }
        cout << endl;
    }
    return out;
}

/*
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
*/
