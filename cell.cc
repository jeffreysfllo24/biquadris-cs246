#include "cell.h"

using namespace std;

Cell::Cell(const int x, const int y) : xCoord{x}, yCoord{y}, letter{""}, livesCounter{-1} {}

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
void Cell::copyData(Cell * other){
    livesCounter = other->livesCounter;
    hasLetter = other->hasLetter;
    hasSet = other->hasSet;
    letter = other->letter;
}

Cell::~Cell() {}
