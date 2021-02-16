#include "cell.h"

using namespace std;

Cell::Cell(const int x, const int y) : rowCord{x}, colCord{y}, letter{""}, livesCounter{-1} {}

bool Cell::isFilled() {
    if (letter == "") { // should change to default cell
        return false;
    }
    return true;
}

int Cell::getRow() {
    return rowCord;
}

int Cell::getCol() {
    return colCord;
}

string Cell::getLetter() {
    return letter;
}

void Cell::setLetter(const string &s) {
    letter = s;
}
void Cell::copyData(Cell * other){
    livesCounter = other->livesCounter;
    letter = other->letter;
}

Cell::~Cell() {}
