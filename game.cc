#include "game.h"
#include <fstream>
#include <cstdlib>
using namespace std;
void Game::generateBlock(int board) {
    char s;
    int level;
    string filename;
    if (board == 1) {
     level = board1->getLevel();
     filename = fileName1;
    } else if (board == 2) {
     level = board2->getLevel();
     filename = fileName2;
    }
    if (level == 0) {
       ifstream readFile(filename);
       if(readFile >> s) {
          if (board == 1) {
            blockNames1.emplace_back(s);
          } else if (board == 2) {
            blockNames2.emplace_back(s);
          }
       } else if (index >= blockNames.size()) {
         index = 0;
         if (board == 1) {
           s = blockNames1[index];
         } else if (board == 2) {
           s = blockNames2[index];
         }
       } else {
         s = blockNames[index];
         index += 1;
       }
    }
    else if (level == 1) {
        int random = rand() % 11;    // returns random from 0-11
        if (random == 0)
            s = 'S';
        else if (random == 1)
            s = 'Z';
        else if (random == 2 || random == 3)
            s = 'I';
        else if (random == 4 || random == 5)
            s = 'L';
        else if (random == 6 || random == 7)
            s = 'O';
        else if (random == 8 || random == 9)
            s = 'T';
        else s = 'J';
    }

    else if (level == 2) {
        int random = rand() % 6;    // returns random from 0-6
        if (random == 0)
            s = 'S';
        else if (random == 1)
            s = 'Z';
        else if (random == 2)
            s = 'I';
        else if (random == 3)
            s = 'L';
        else if (random == 4)
            s = 'O';
        else if (random == 5)
            s =  'T';
        else s = 'J';
    }

    else {              // either level 3 or 4 
        int random = rand() % 8;    // returns random from 0-8
        if (random == 0 || random == 1)
            s = 'S';
        else if (random == 2 || random == 3)
            s = 'Z';
        else if (random == 4)
            s = 'I';
        else if (random == 5)
            s = 'L';
        else if (random == 6)
            s = 'O';
        else if (random == 7)
            s = 'T';
        else s = 'J';
    }
   shared_ptr<Block> shared_b(new Block(s,1,level));
   if (board == 1) {
     nextBlock1 = shared_b;
   } else if (board == 2) {
     nextBlock2 = shared_b; 
   }
}

void Game::resetBoard(int board) {
  if (board == 1) {
    board1->reset();
  } else if (board == 2) {
     board2->reset();
  }
}

bool Game::moveBlock(char dir, int board) {
  shared_ptr<AbstractBoard> b;
  shared_ptr<Block> cb;
  if (board == 1) {
    shared_ptr<AbstractBoard> b = board1;
    shared_ptr<Block> cb = currentBlock1;
  } else if (board == 2) {
    shared_ptr<AbstractBoard> b = board2;
    shared_ptr<Block> cb = currentBlock2;
  }
  if (dir == 'l') {// char l stands for left
    if (b->moveLeft(cb)) {
      cb->moveLeft();
      return true;
    } 
  } else if (dir == 'd') {// char d stands for down
    if (b->moveDown(cb)) {
      cb->moveDown();
      return true;
    } 
  } else if (dir == 'r') {// char r stands for right
    if (b->moveRight(cb)) {
      cb->moveRight();
      return true;
    }
  }
  return false;
}

bool Game::rotateBlock(char dir, int board) {
  shared_ptr<AbstractBoard> b;
  shared_ptr<Block> cb;
  if (board == 1) {
    shared_ptr<AbstractBoard> b = board1;
    shared_ptr<Block> cb = currentBlock1;
  } else if (board == 2) {
    shared_ptr<AbstractBoard> b = board2;
    shared_ptr<Block> cb = currentBlock2;
  }

  if (dir == 'w') {// char w stands for clockwise
    if (b->rotateCW(cb)) {
      cb->rotateCW();
      return true;
    }
  } else if (dir == 'c') {// char c stands for counter-clockwise
    if (b->rotateCCW(cb)) {
      cb->rotateCCW();
      return true;
    }
  }
  return false;
}

void Game::replaceBlock(char blockType, int block) {
  int x;
  int y;
  int level;
  if (block == 1) {
    level = currentBlock1->getX();
    x = currentBlock1->getX();
    y = currentBlock1->getY();
  } else if (block == 2) {
    level = currentBlock2->getY(); 
    x = currentBlock2->getX();
    y = currentBlock2->getY();
  }
  shared_ptr<Block> nb(new Block(blockType, 1, level));
  nb->setX(x);
  nb->setY(y);
  if (block == 1) {
    currentBlock1 = nb;
  } else if (block == 2) {
    currentBlock2 = nb;
  }
}

void Game::changeLevel(int change, int board) {
  if (board == 1) {
     board1->changeLevel(change);
  } else if (board == 2) {
     board2->changeLevel(change);
  }
}

void Game::drop(int board) {
  if (board == 1) {
     board1->drop();
  } else if (board == 2) {
     board2->drop();
  }
}

void Game::endTurn() {

}

void Game::setFilename1(string fn) {
  fileName1 = fn;
}

void Game::setFilename2(string fn) {
   fileName2 = fn;
} 
