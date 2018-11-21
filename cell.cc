#include "cell.h"

Cell::Cell(const int x, const int y) : xCoord{x}, yCoord{y}, letter{0}, livesCounter{-1} {}

bool Cell::isFilled() {
    if (letter == 0) {
        return false;
    }
    return true;
}

int Cell::getX() {
    return xCoord;
}

int Cell::getY() {
    return yCoord;
}

char Cell::getLetter() {
    return letter;
}

void Cell::setLetter(const char &c) {
    letter = c;
}

Cell::~Cell() {}
