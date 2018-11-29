#include "block.h"
using namespace std;
// implementation of block constructor
Block::Block(string name, int levelCreated): name{name}, container{}, levelCreated{levelCreated} {}

// implementation of setBlock method
void Block::setBlock() {
  // for I type of block
  if (name == "I") { // container is of size 1 * 4 for block I
    this->setHeightt
    Cell cell;
    <vector Cell> row(4, cell);
    <vector <vector Cell>> copy_container(1, row);
    container = copy_container; // successuly create a 4*4 container
    int i = 3; // i is y value
    for (int j = 0; j < 4; j = j + 1) {// j is x value
       container[i][j].setX(j);
       container[i][j].setY(i);
       container[i][j].setLetter("I");
    }
   return;
  }
  // for O type of block
  if (name == "O") { // container is of size 2 * 2 for block O 
    Cell cell;
    <vector Cell> row(2, cell);
    <vector <vector Cell>> copy_container(2, row);
    container = copy_container; // successuly create a 2*2 container
    for (int i = 0; i < 2; i = i + 1) {// (i+2) is y value
      for (int j = 0; j < 2; j = j + 1) {// j is x value
         container[i][j].setX(j);
         container[i][j].setY(i+2);
         container[i][j].setLetter("O");
       }
     }
   return;
  }
  Cell cell;
  <vector Cell> row(3, cell); 
  <vector <vector Cell>> copy_container(2, row);
  container = copy_container; // succesfully create a 2 * 3 container 
  // for J type of block
  if (name == "J") {
    for (int i = 0; i < 2; i = i + 1) {
      for (int j = 0; j < 3; j = j + 1) {
        container[i][j].setX(j);
        container[i][j].setY(i+2);
        if ((i+2) == 3 || (i == 0 && j == 0)) {
          container.[i][j].setLetter("J");
        } else {
          container.[i][j].setLetter("");
        } 
      }
    }
   return;
  } 
  // for L type of block
  else if (name = "L") {
    for (int i = 0; i < 2; i = i + 1) {
     for (int j = 0; j < 3; j = j + 1) {
        container[i][j].setX(j);
        container[i][j].setY(i+2);
        if (((i+2) == 3) || ((i+2) == 2 && j == 2)) {
          container.[i][j].setLetter("L"); 
        } else {
          container.[i][j].setLetter("");
        } 
      }
    }
   return;
  }
  // for S type of block 
  else if (name == "S") {
    for (int i = 0; i < 2; i = i + 1) {
     for (int j = 0; j < 3; j = j + 1) {
        container[i][j].setX(j);
        container[i][j].setY(i+2); 
        if ((j == 1) || ((i+2) == 3 && j == 0) || ((i+2) == 2 && j == 2)) {
          container.[i][j].setLetter("S");
        } else {
          container.[i][j].setLetter("");
        }
      }
    }
   return;
  }
  // for Z type of block
  else if (name == "Z") {
    for (int i = 0; i < 2; i = i + 1) {
     for (int j = 0; j < 3; j = j + 1) {
        container[i][j].setX(j);
        container[i][j].setY(i+2);
        if ((j == 1) || ((i+2) == 2 && j == 0) || ((i+2) == 3 && j == 2)) {
          container.[i][j].setLetter("Z");
        } else {
          container.[i][j].setLetter("");
        }
      }
    }
   return;
  }
  // for T type of block
  else {
     for (int i = 0; i < 2; i = i + 1) {
      for (int j = 0; j < 3; j = j + 1) {
        container[i][j].setX(j);
        container[i][j].setY(i+2);
        if (((i+2) == 2) || (((i+2) == 3) && (j == 1))) {
          container.[i][j].setLetter("T");
        } else {
          container.[i][j].setLetter("");
        }
      }
    }
   return;
  }
}

// implmentation of moveLeft method
void Block::moveLeft() {
  vector<vector<Cell>>::iterator it_1;
  vector<Cell>::iterator it_2;
  for (it_1 = container.begin(); it_1 != container.end(); it_1++) {
    for (it_2 = it_1->begin(); it_2 != it_1->end(); it_2++) {
     it_2->setX((it_2->getX()) - 1);
   }
  }
}
// implementation of moveRight method
void Block:;moveRight() {
  vector<vector<Cell>>::iterator it_1;
  vector<Cell>::iterator it_2;
  for (it_1 = container.begin(); it_1 != container->end(); it_1++) {
    for (it_2 = it_1->begin(); it_2 != it_1->end(); it_2++) {
     it_2->setX((it_2->getX()) + 1);
   }
  }
}

// implmentation of moveUp method
void Block:;moveUp() {
  vector<vector<Cell>>::iterator it_1;
  vector<Cell>::iterator it_2;
  for (it_1 = container.begin(); it_1 != container->end(); it_1++) {
    for (it_2 = it_1->begin(); it_2 != it_1->end(); it_2++) {
     it_2->setY((it_2->getY()) + 1);
   }
  }
}
// implmentation of moveDown method
void Block::moveDown() {
  vector<vector<Cell>>::iterator it_1;
  vector<Cell>::iterator it_2;
  for (it_1 = container.begin(); it_1 != container->end(); it_1++) {
    for (it_2 = it_1->begin(); it_2 != it_1->end(); it_2++) {
     it_2->setY((it_2->getY()) - 1);
   }
  }
}

// implmentation of clockwise rotation
void Block::rotateCW() {
  int height = container.size();
  int width  = (container.begin())->size();
  int left_corner_x = container[height-1][0].getX();
  int left_corner_y = container[height-1][0].getY(); 
  vector<Cell> row;
  vector< vector<Cell>> rotatedContainer(width, row);
  for (int i = (height-1); i >= 0; i = i - 1) {
    for (int j = 0; j < width; j = j + 1) {
      (rotatedContainer[j]).emplace_back(container[i][j]);
   }
  }
  for (int i = 0; i < width; i = i + 1) {
    for (int j = 0; j < height; j = j + 1) {
     rotatedContainer[i][j].setX(left_corner_x + j);
     rotatedContainer[i][j].setY(left_corner_y - (width - 1 - i));
   }
  }
  container = rotatedContainer;
}
// implmentation of counter clockwise rotation
void Block::rotateCCW() {
  int height = container.size();
  int width  = (container.begin())->size();
  int left_corner_x = container[height-1][0].getX();
  int left_corner_y = container[height-1][0].getY();
  vector<Cell> row;
  vector< vector<Cell>> rotatedContainer(width, row);
  for (int i = 0; i < height; i = i + 1) {
    for (int j = (width - 1); j >= 0; j = j - 1) {
      (rotatedContainer[j]).emplace_back(container[i][j]);
   }
  }
  for (int i = 0; i < width; i = i + 1) {
    for (int j = 0; j < height; j = j + 1) {
     rotatedContainer[i][j].setX(left_corner_x + j);
     rotatedContainer[i][j].setY(left_corner_y - (width - 1 - i));
   }
  }
  container = rotatedContainer;
}


