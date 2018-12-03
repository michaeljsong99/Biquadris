#include "game.h"
#include <fstream>
#include <cstdlib>

using namespace std;

Game::Game() {
    auto empty = make_shared<Block>('/0', 1, 0);
    e = empty;
    b1 = make_shared<Board>();
}

bool Game::moveBlock(char dir, int board, int n) {
    if (board == 1) {
        if (dir == 'l') {// char l stands for left
            return b1->moveLeft(n);
        } else if (dir == 'd') {// char d stands for down
            return b1->moveDown(n);
        } else if (dir == 'r') {// char r stands for right
            return b1->moveRight(n);
        }
    } else {
        if (dir == 'l') {// char l stands for left
            return b2->moveLeft(n);
        } else if (dir == 'd') {// char d stands for down
            return b2->moveDown(n);
        } else if (dir == 'r') {// char r stands for right
            return b2->moveRight(n);
        }
    }
    return false;
}

bool Game::rotateBlock(char dir, int board, int n) {
    if (board == 1) {
        if (dir == 'c') {// char c stands for clockwise
            return b1->rotateCW(n);
        } else if (dir == 'w') {// char w stands for counter-clockwise
            return b1->rotateCCW(n);
        }
    } else {
        if (dir == 'c') {// char c stands for clockwise
            return b2->rotateCW(n);
        } else if (dir == 'w') {// char w stands for counter-clockwise
            return b2->rotateCCW(n);
        }
    }
    return false;
}

void Game::drop(int board) {
    if (board == 1) {
        b1->drop();
    } else {
        b2->drop();
    }
}

void Game::replaceBlock(char blockType, int board) {
    int x, y, level;

    if (board == 1) {
        level = b1->getLevel();
        x = cBlock1->getX();
        y = cBlock1->getY();
    } else {
        level = b2->getLevel();
        x = cBlock2->getX();
        y = cBlock2->getY();
    }

    auto nb = make_shared<Block>(blockType, 1, level);
    nb->setX(x);
    nb->setY(y);

    if (board == 1) {
        cBlock1 = nb;
        b1->setCurrentBlock(nb);
    } else {
        cBlock2 = nb;
        b2->setCurrentBlock(nb);
    }
}

void Game::setFile1(string fn) {
    f1 = ifstream(fn);
}

void Game::setFile2(string fn) {
    f2 = ifstream(fn);
}

void Game::resetBoard(int board) { //!May need to do more?
    if (board == 1) {
        b1->reset();
    } else if (board == 2) {
        b2->reset();
    }
}


void Game::generateBlock(int board) {
    char c;
    int level;

    if (board == 1) {
        level = b1->getLevel();
    } else {
        level = b2->getLevel();
    }

    if (level == 0) {
        if (board == 1) {
            f1 >> c;
            if(f1.eof()) {
                f1.clear();
                f1.seekg(0);
                f1 >> c;
            }
        } else {
            f2 >> c;
            if(f2.eof()) {
                f1.clear();
                f1.seekg(0);
                f2 >> c;
            }
        }

    } else if (level == 1) {
        int random = rand() % 11;    // returns random from 0-11
        if (random == 0)
            c = 'S';
        else if (random == 1)
            c = 'Z';
        else if (random == 2 || random == 3)
            c = 'I';
        else if (random == 4 || random == 5)
            c = 'L';
        else if (random == 6 || random == 7)
            c = 'O';
        else if (random == 8 || random == 9)
            c = 'T';
        else c = 'J';
    } else if (level == 2) {
        int random = rand() % 6;    // returns random from 0-6
        if (random == 0)
            c = 'S';
        else if (random == 1)
            c = 'Z';
        else if (random == 2)
            c = 'I';
        else if (random == 3)
            c = 'L';
        else if (random == 4)
            c = 'O';
        else if (random == 5)
            c = 'T';
        else c = 'J';
    } else {              // either level 3 or 4
        int random = rand() % 8;    // returns random from 0-8
        if (random == 0 || random == 1)
            c = 'S';
        else if (random == 2 || random == 3)
            c = 'Z';
        else if (random == 4)
            c = 'I';
        else if (random == 5)
            c = 'L';
        else if (random == 6)
            c = 'O';
        else if (random == 7)
            c = 'T';
        else c = 'J';
    }
    auto nb = make_shared<Block>(c, 1, level);
    if (board == 1) {
        nBlock1 = nb;
    } else {
        nBlock2 = nb;
    }
}


void Game::changeLevel(int change, int board) {
    if (board == 1) {
        b1->changeLevel(change);
    } else if (board == 2) {
        b2->changeLevel(change);
    }
}

void Game::endTurn(int board) {
    if (board == 1) {
        cBlock1 = nBlock1;
        nBlock1 = e;
        this->generateBlock(2);
    } else {
        cBlock2 = nBlock2;
        nBlock2 = e;
        this->generateBlock(1);
    }
}


void Game::setLevel(int level) {
    b1.setLevel(level);
    b2.setLevel(level);
}
