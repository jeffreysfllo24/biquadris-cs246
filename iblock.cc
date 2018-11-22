#include "iblock.h"

using namespace std;

// TODO: MUST ACCOUNT FOR WHEN WE KNOW BLOCK IS DONE

IBlock::IBlock(Cell *cell, Cell ***grid) : bottomLeft{cell}, blockGrid{grid}, isBottom{false}, rotation{0}, maxWidth{1} {
    // initial cells
    Cell * firstCell = blockGrid[1][3];
    Cell * secondCell = blockGrid[2][3];
    Cell * thirdCell = blockGrid[3][3];
    // add to vector
    blockCells.push_back(bottomLeft);
    blockCells.push_back(firstCell);
    blockCells.push_back(secondCell);
    blockCells.push_back(thirdCell);
}

string IBlock::getType() const {
    return "I";
}

bool IBlock::isValidMove(vector<Cell *> newBlockCells) const {
    for (int i = 0; i < newBlockCells.size(); i++) {
        if (newBlockCells[i]->isFilled()) { // check if cell is already occupied by another block
            return false;
        }
    }
    return true; // newBlockCells does not overlap any existing blocks
}

void IBlock::replaceCells(vector<Cell *> cells) {
    if (isValidMove(cells)) {
        for (int i = 0; i < blockCells.size(); i++) {
            blockCells[i]->setLetter(""); // set old block cells to empty letter
        }
        blockCells.clear(); // remove all past cells from vector
        blockCells = cells; // reassign vector to new cells
    }
}

// GET POSITION METHODS =================================================

vector<Cell *> IBlock::getPositionZero() {
    int bottomLeftX = bottomLeft->getX();
    int bottomLeftY = bottomLeft->getY();
    vector<Cell *> tempCells;
    // add new rotation to tempCells
    tempCells.push_back(bottomLeft);
    tempCells.push_back(blockGrid[bottomLeftX+1][bottomLeftY]);
    tempCells.push_back(blockGrid[bottomLeftX+2][bottomLeftY]);
    tempCells.push_back(blockGrid[bottomLeftX+3][bottomLeftY]);
    return tempCells;
}

vector<Cell *> IBlock::getPositionOne() {
    int bottomLeftX = bottomLeft->getX();
    int bottomLeftY = bottomLeft->getY();
    vector<Cell *> tempCells;
    // add new rotation to tempCells
    tempCells.push_back(bottomLeft);
    tempCells.push_back(blockGrid[bottomLeftX][bottomLeftY-1]);
    tempCells.push_back(blockGrid[bottomLeftX][bottomLeftY-2]);
    tempCells.push_back(blockGrid[bottomLeftX][bottomLeftY-3]);
    return tempCells;
}

// ======================================================================

void IBlock::clockwise() {
    vector<Cell *> newRotation;
    if (rotation == 0 || rotation == 2) { // same rotation for positions 0 and 2
        newRotation = getPositionOne();
        if (isValidMove(newRotation)) {
            maxWidth = 1;
            rotation++;
        }
    } else if (rotation == 1 || rotation == 3) { // same rotation for positions 1 and 3
        if (bottomLeft->getX() + 4 > 10) {
            return; // can't rotate
        }
        if (isValidMove(newRotation)) {
            maxWidth = 4;
            if (rotation == 1) rotation++;
            else rotation = 0;
        }
    }
    replaceCells(newRotation);
}

void IBlock::counterclockwise() {
    vector<Cell *> newRotation;
    if (rotation == 0 || rotation == 2) { // same rotation for positions 0 and 2
        newRotation = getPositionOne();
        if (isValidMove(newRotation)) {
            maxWidth = 1;
            if (rotation == 2) rotation--;
            else rotation = 3;
        }
    } else if (rotation == 1 || rotation == 3) { // same rotation for positions 1 and 3
        if (bottomLeft->getX() + 4 > 10) {
            return; // can't rotate
        }
        if (isValidMove(newRotation)) {
            maxWidth = 4;
            rotation--;
        }
    }
    replaceCells(newRotation);
}

void IBlock::left() {
    if (bottomLeft->getX() == 0) {
        return; // can't move left
    }
    vector<Cell *> newMovement;
    int curX, curY;
    for (int i = 0; i < blockCells.size(); i++) {
        curX = blockCells[i]->getX();
        curY = blockCells[i]->getY();
        newMovement.push_back(blockGrid[curX-1][curY]);
    }
    replaceCells(newMovement);
}

void IBlock::right() {
    if (bottomLeft->getX() + maxWidth > 10) {
        return; // can't move right
    }
    vector<Cell *> newMovement;
    int curX, curY;
    for (int i = 0; i < blockCells.size(); i++) {
        curX = blockCells[i]->getX();
        curY = blockCells[i]->getY();
        newMovement.push_back(blockGrid[curX+1][curY]);
    }
    replaceCells(newMovement);
}

void IBlock::down() {
    if (bottomLeft->getY() == 0) {
        isBottom = true;
        return; // can't move down, at bottom row
    }
    if (!isBottom) {
        vector<Cell *> newMovement;
        int curX, curY;
        for (int i = 0; i < blockCells.size(); i++) {
            curX = blockCells[i]->getX();
            curY = blockCells[i]->getY();
            newMovement.push_back(blockGrid[curX][curY+1]);
        }
        if (!isValidMove(newMovement)) isBottom = true; // overlapping cells below means block is at bottom
        replaceCells(newMovement);
    }
}

void IBlock::drop() {
    while (!isBottom) {
        down(); // recursively call down until block is at bottom
    }
}

IBlock::~IBlock() {
    bottomLeft = nullptr;
    blockGrid = nullptr;
    blockCells.clear();
}
