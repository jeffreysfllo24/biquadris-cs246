#include "cell.h"

Cell::Cell(const int x, const int y) : xCoord(x), yCoord(y), hasLetter{false},livesCounter(-1) {}

bool Cell::isSet() {
    return hasSet;
}

bool Cell::isFilled() {
    return hasLetter;
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
    hasLetter = true;
}
void Cell::copyData(Cell * other){
    livesCounter = other->livesCounter;
    hasLetter = other->hasLetter;
    hasSet = other->hasSet;
    letter = other->letter;
}

Cell::~Cell() {}
