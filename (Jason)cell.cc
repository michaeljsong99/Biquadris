#include "cell.h"
using namespace std;

string Cell::getLetter() {
  return letter;
}

void Cell::setLetter(string alphabet) {
  letter = alphabet;
}

int Cell::getX() {
  return x;
}

int Cell::getY() {
  return y;
}

void Cell::setX(int n) {
   x = n;
}

void Cell::setY(int m) {
   y = m;
}

std::ostream& ::operator<<(std::ostream &out, const Block &b){
    for (int i = 0; i < b.container_height; ++i) {
        for (int j = 0; j < b.container_width; ++j) {
            cout << b.container[i][j];
        }
        cout << endl;
    }
    return out;
}
