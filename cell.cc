#include "cell.h"

Cell::Cell(Coordinate &c) : coord{c}, hasLetter{false} {}

bool Cell::isFilled() {
    return hasLetter;
}

char Cell::getLetter() {
    if (hasLetter) {
        return letter;
    }
    return;
}

void Cell::setLetter(const char &c) {
    letter = c;
}

Cell::~Cell() {}
