#include "iblock.h"

using namespace std;

IBlock::IBlock(Cell *cell, Cell ***grid) : rotation{0}, bottomLeft{cell}, blockGrid{grid} {
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

char IBlock::prettyPrint() const {
    return 'I';
}

bool IBlock::isValidMove(vector<Cell *> newBlockCells) const {
    for (int i = 0; i < newBlockCells.size(); i++) {
        if (newBlockCells[i]->isFilled()) {
            return false;
        }
    }
    return true;
}

void IBlock::replaceCells(vector<Cell *> cells) {
    if (isValidMove(cells)) {
        for (int i = 0; i < blockCells.size(); i++) {
            blockCells[i]->setLetter(0);
        }
        blockCells.clear();
        blockCells = cells;
    }
}

void IBlock::clockwise() {
    int bottomLeftX = bottomLeft->getX();
    int bottomLeftY = bottomLeft->getY();
    vector<Cell *> tempCells;
    if (rotation == 0 || rotation == 2) {
        tempCells.push_back(bottomLeft);
        tempCells.push_back(blockGrid[bottomLeftX][bottomLeftY-1]);
        tempCells.push_back(blockGrid[bottomLeftX][bottomLeftY-2]);
        tempCells.push_back(blockGrid[bottomLeftX][bottomLeftY-3]);
        if (isValidMove(tempCells)) maxWidth = 1;
    } else if (rotation == 1 || rotation == 3) {
        if (bottomLeft->getX() + 4 > 10) {
            return; // can't rotate
        }
        tempCells.push_back(bottomLeft);
        tempCells.push_back(blockGrid[bottomLeftX+1][bottomLeftY]);
        tempCells.push_back(blockGrid[bottomLeftX+2][bottomLeftY]);
        tempCells.push_back(blockGrid[bottomLeftX+3][bottomLeftY]);
        if (isValidMove(tempCells)) maxWidth = 4;
    }
    replaceCells(tempCells);
}

void IBlock::counterclockwise() {
    int bottomLeftX = bottomLeft->getX();
    int bottomLeftY = bottomLeft->getY();
    vector<Cell *> tempCells;
    if (rotation == 0 || rotation == 2) {
        tempCells.push_back(bottomLeft);
        tempCells.push_back(blockGrid[bottomLeftX][bottomLeftY-1]);
        tempCells.push_back(blockGrid[bottomLeftX][bottomLeftY-2]);
        tempCells.push_back(blockGrid[bottomLeftX][bottomLeftY-3]);
        if (isValidMove(tempCells)) maxWidth = 1;
    } else if (rotation == 1 || rotation == 3) {
        if (bottomLeft->getX() + 4 > 10) {
            return; // can't rotate
        }
        tempCells.push_back(bottomLeft);
        tempCells.push_back(blockGrid[bottomLeftX+1][bottomLeftY]);
        tempCells.push_back(blockGrid[bottomLeftX+2][bottomLeftY]);
        tempCells.push_back(blockGrid[bottomLeftX+3][bottomLeftY]);
        if (isValidMove(tempCells)) maxWidth = 4;
    }
    replaceCells(tempCells);
}

void IBlock::left() {
    if (bottomLeft->getX() == 0) {
        return; // can't move left
    }
    vector<Cell *> tempCells;
    int curX, curY;
    for (int i = 0; i < blockCells.size(); i++) {
        curX = blockCells[i]->getX();
        curY = blockCells[i]->getY();
        tempCells.push_back(blockGrid[curX-1][curY]);
    }
    replaceCells(tempCells);
}

void IBlock::right() {
    if (bottomLeft->getX() + maxWidth == 10) {
        return; // can't move right
    }
    vector<Cell *> tempCells;
    int curX, curY;
    for (int i = 0; i < blockCells.size(); i++) {
        curX = blockCells[i]->getX();
        curY = blockCells[i]->getY();
        tempCells.push_back(blockGrid[curX+1][curY]);
    }
    replaceCells(tempCells);
}

void IBlock::down() {
    // check if you're on bottom row
    int bottomLeftY = bottomLeft->getY();
    if (bottomLeftY == 0) {
        isBottom = true;
        return; // can't move down
    }
    if (!isBottom) {
        vector<Cell *> tempCells;
        int curX, curY;
        for (int i = 0; i < blockCells.size(); i++) {
            curX = blockCells[i]->getX();
            curY = blockCells[i]->getY();
            tempCells.push_back(blockGrid[curX][curY+1]);
        }
        if (!isValidMove(tempCells)) isBottom = true;
        replaceCells(tempCells);
    }
}

void IBlock::drop() {
    while (!isBottom) {
        down();
    }
}

IBlock::~IBlock() {
    bottomLeft = nullptr;
    blockGrid = nullptr;
    blockCells.clear();
}
