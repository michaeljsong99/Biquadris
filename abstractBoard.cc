
#include "abstractBoard.h"

AbstractBoard::~AbstractBoard() {}

std::ostream &operator<<(std::ostream &out, const AbstractBoard &b) {
    return out << b.printBoard();
}
