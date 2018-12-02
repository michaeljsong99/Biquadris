
#include "blind.h"

using namespace std;

Blind::Blind(std::shared_ptr<AbstractBoard> ab) : Decorator(ab) {}

std::string Blind::printBoard() const{

    string s = component->printBoard();

    for(int i = 96; i < 204 ;i+=12) {
        for (int j = 2; j < 9 ; j++) {
            s[i+j] = '?';
        }
    }
    return s;
}
