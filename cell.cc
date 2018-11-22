#include "cell.h"

using namespace std;

Cell::Cell(const int x, const int y) : xCoord{x}, yCoord{y}, letter{0}, livesCounter{-1} {}

bool Cell::isFilled() {
    if (letter == "") { // should change to default cell
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

string Cell::getLetter() {
    return letter;
}

void Cell::setLetter(const string &s) {
    letter = s;
}

Cell::~Cell() {}
