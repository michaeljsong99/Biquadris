#include "game.h"
#include "heavy.h"
#include <fstream>
#include <cstdlib>
#include <sstream>

using namespace std;

Game::Game() {
    b1 = make_shared<Board>();
    b1 = make_shared<Heavy>(b1, 0, false);
    b2 = make_shared<Board>();
    b2 = make_shared<Heavy>(b2, 0, false);
    setLevel(0);
    auto empty = make_shared<Block>('\0', 1, 0);
    e = empty;

}

void Game::init() {
    cBlock1 = generateBlock(1);
    nBlock1 = generateBlock(1);
    cBlock2 = generateBlock(2);
    nBlock2 = e;//generateBlock(2);
    b1->setCurrentBlock(cBlock1);
    b2->setCurrentBlock(cBlock2);
    b1->setNextBlock(nBlock1);
    b2->setNextBlock(e);
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
        cout << "Dropping" << endl;
        b1->drop();
        cout << "Dropped!" << endl;
    } else {
        b2->drop();
    }
    endTurn(board);
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

void Game::setFileRandom(string fn) {
    fRandom = ifstream(fn);
}

void Game::resetBoard() { //!May need to do more?
    b1->reset();
    b2->reset();
    if(stateGameOver) {
        cout << "  ________                        ________                     " << endl;
        cout << " /  _____/_____    _____   ____   \\_____  \\___  __ ___________ " << endl;
        cout << "/   \\  ___\\__  \\  /     \\_/ __ \\   /   |   \\  \\/ // __ \\_  __ \\" << endl;
        cout << "\\    \\_\\  \\/ __ \\|  Y Y  \\  ___/  /    |    \\   /\\  ___/|  | \\/" << endl;
        cout << " \\______  (____  /__|_|  /\\___  > \\_______  /\\_/  \\___  >__|   " << endl;
        cout << "        \\/     \\/      \\/     \\/          \\/          \\/       " << endl;
    }
    stateGameOver = false;
    init();
}


shared_ptr<Block> Game::generateBlock(int board) {
    char c;
    int level;

    if (board == 1) {
        level = b1->getLevel();
    } else {
        level = b2->getLevel();
    }

    if(!isRandom) {
        fRandom >> c;
        if(fRandom.eof()) {
            fRandom.clear();
            fRandom.seekg(0);
            fRandom >> c;
        }
    }
    else if (level == 0) {
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
    return nb;
}


void Game::changeLevel(int change, int board) {
    if (board == 1) {
        b1->changeLevel(change);
        if(b1->getLevel() >= 3) {
            b1->setHeavy(1);
        } else {
            b1->setHeavy(0);
        }
    } else if (board == 2) {
        b2->changeLevel(change);
        if(b2->getLevel() >= 3) {
            b2->setHeavy(1);
        } else {
            b2->setHeavy(0);
        }
    }
}

void Game::endTurn(int board) {
    if (board == 1) {
        if (b1->isGameOver()) {
            stateGameOver = true;
            resetBoard();

        } else {
            cBlock1 = nBlock1;
            nBlock1 = e;
            nBlock2 = generateBlock(2);
            b1->setCurrentBlock(cBlock1);
            b1->setNextBlock(nBlock1);
            b2->setNextBlock(nBlock2);
        }
    } else {
        if (b2->isGameOver()) {
            stateGameOver = true;
            resetBoard();
        } else {
            cBlock2 = nBlock2;
            nBlock2 = e;
            nBlock1 = generateBlock(1);
            b2->setCurrentBlock(cBlock2);
            b2->setNextBlock(nBlock2);
            b1->setNextBlock(nBlock1);
        }
    }
}

void Game::setLevel(int level) {
    b1->setLevel(level);
    b2->setLevel(level);
    if(level >= 3) {
        b1->setHeavy(1);
        b2->setHeavy(1);
    } else {
        b1->setHeavy(0);
        b2->setHeavy(0);
    }
}

void Game::setGraphics(bool b) {
    graphics = b;
}

void Game::setRandom(bool b) {
    isRandom = b;
}

std::string Game::printGame() const{
    ostringstream oss;

    string space = "     ";

    b1->updateGrid();
    b2->updateGrid();
    b1->drawCurrentBlock();
    b2->drawCurrentBlock();
    string board1 = b1->printBoard();
    string board2 = b2->printBoard();
    b1->updateGrid();
    b2->updateGrid();

    for (int i = 0; i < 25; i+=1) {
        for (int j = 0 ; j < 11; j++) {
            oss << board1[(i*12) + j];
        }
        oss << space;
        for (int j = 0 ; j < 11; j++) {
            oss << board2[(i*12) + j];
        }
        oss << endl;
    }
    return oss.str();
}

std::ostream &operator<<(std::ostream &out, const Game &g) {
    return out << g.printGame();
}
