#include "cell.h"

Cell::Cell(const int x, const int y) : xcord(x), ycord(y), hasLetter{false} {}

bool Cell::isFilled() {
    return hasLetter;
}

char Cell::getLetter() {
    return letter;
}

void Cell::setLetter(const char &c) {
    letter = c;
    hasLetter = true;
}

Cell::~Cell() {}
