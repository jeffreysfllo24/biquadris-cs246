#include "tblock.h"

using namespace std;

TBlock::TBlock(){
    this->bottomLeft = nullptr;
    this->isBottom = false;
    this->rotation = 0;
    this->maxWidth = 3;
    this->level = 0;
}

void TBlock::init(Cell * cell, vector<vector<Cell *>> grid) {
    bottomLeft = cell;
    blockGrid = grid;
    if (didLose()) {
        throw runtime_error("Game Over");
    }
    // create pointers to cells in the block
    Cell * zeroCell = blockGrid[3][1];
    zeroCell->setLetter("T");
    Cell * firstCell = blockGrid[2][0];
    firstCell->setLetter("T");
    Cell * secondCell = blockGrid[2][1];
    secondCell->setLetter("T");
    Cell * thirdCell = blockGrid[2][2];
    thirdCell->setLetter("T");
    // add to vector
    blockCells.push_back(zeroCell);
    blockCells.push_back(firstCell);
    blockCells.push_back(secondCell);
    blockCells.push_back(thirdCell);
}

bool TBlock::didLose(){
    if (blockGrid[3][1]->isFilled() || blockGrid[2][0]->isFilled() || blockGrid[2][1]->isFilled() || blockGrid[2][2]->isFilled()) {
        return true;
    }
    return false;
}

string TBlock::getType() const {
    return "T";
}

Cell * TBlock::getBottomLeft() const {
    return bottomLeft;
}

vector<Cell *> TBlock::getBlockCells() const {
    return blockCells;
}

bool TBlock::isValidMove(vector<Cell *> newBlockCells) const {
    for (int i = 0; i < blockCells.size(); i++) {
        blockCells[i]->setLetter(""); // temporarily set old block cells to empty letter
    }
    for (int i = 0; i < newBlockCells.size(); i++) {
        if (newBlockCells[i]->isFilled()) { // check if cell is already occupied by another block
            for (int i = 0; i < blockCells.size(); i++) {
                blockCells[i]->setLetter("T"); // temporarily set old block cells to empty letter
            }
            return false;
        }
    }
    return true; // newBlockCells does not overlap any existing blocks
}

bool TBlock::replaceCells(vector<Cell *> cells, string letter) {
    if (isValidMove(cells)) {
        for (int i = 0; i < blockCells.size(); i++) {
            cells[i]->setLetter(letter);
        }
        // set bottomLeft
        if (rotation == 0 || rotation == 1) {
            int firstRow = cells[0]->getRow();
            int firstCol = cells[0]->getCol();
            bottomLeft = blockGrid[firstRow][firstCol-1];
        } else if (rotation == 2 || rotation == 3) {
            bottomLeft = cells[0];
        }
        blockCells.clear(); // remove all past cells from vector
        blockCells = cells; // reassign vector to new cells
        return true;
    }
    return false;
}

vector<Cell *> TBlock::getPositionZero() {
    int bottomLeftRow = bottomLeft->getRow();
    int bottomLeftCol = bottomLeft->getCol();
    vector<Cell *> tempCells;
    // add new rotation to tempCells
    tempCells.push_back(blockGrid[bottomLeftRow][bottomLeftCol+1]);
    tempCells.push_back(blockGrid[bottomLeftRow-1][bottomLeftCol]);
    tempCells.push_back(blockGrid[bottomLeftRow-1][bottomLeftCol+1]);
    tempCells.push_back(blockGrid[bottomLeftRow-1][bottomLeftCol+2]);
    return tempCells;
}

vector<Cell *> TBlock::getPositionOne() {
    int bottomLeftRow = bottomLeft->getRow();
    int bottomLeftCol = bottomLeft->getCol();
    vector<Cell *> tempCells;
    // add new rotation to tempCells
    tempCells.push_back(blockGrid[bottomLeftRow][bottomLeftCol+1]);
    tempCells.push_back(blockGrid[bottomLeftRow-1][bottomLeftCol]);
    tempCells.push_back(blockGrid[bottomLeftRow-1][bottomLeftCol+1]);
    tempCells.push_back(blockGrid[bottomLeftRow-2][bottomLeftCol+1]);
    return tempCells;
}

vector<Cell *> TBlock::getPositionTwo() {
    int bottomLeftRow = bottomLeft->getRow();
    int bottomLeftCol = bottomLeft->getCol();
    vector<Cell *> tempCells;
    // add new rotation to tempCells
    tempCells.push_back(blockGrid[bottomLeftRow][bottomLeftCol]);
    tempCells.push_back(blockGrid[bottomLeftRow][bottomLeftCol+1]);
    tempCells.push_back(blockGrid[bottomLeftRow][bottomLeftCol+2]);
    tempCells.push_back(blockGrid[bottomLeftRow-1][bottomLeftCol+1]);
    return tempCells;
}

vector<Cell *> TBlock::getPositionThree() {
    int bottomLeftRow = bottomLeft->getRow();
    int bottomLeftCol = bottomLeft->getCol();
    vector<Cell *> tempCells;
    // add new rotation to tempCells
    tempCells.push_back(blockGrid[bottomLeftRow][bottomLeftCol]);
    tempCells.push_back(blockGrid[bottomLeftRow-1][bottomLeftCol]);
    tempCells.push_back(blockGrid[bottomLeftRow-1][bottomLeftCol+1]);
    tempCells.push_back(blockGrid[bottomLeftRow-2][bottomLeftCol]);
    return tempCells;
}

void TBlock::clockwise() {
    vector<Cell *> newRotation;
    if (rotation == 0) {
        try {
            newRotation = getPositionOne();
        } catch (...) {
            return;
        }
        if (isValidMove(newRotation)) {
            maxWidth = 2;
            rotation++;
        }
    } else if (rotation == 1) {
        if (bottomLeft->getRow() + 3 > 10) {
            return; // can't rotate
        }
        try {
            newRotation = getPositionTwo();
        } catch (...) {
            return;
        }
        if (isValidMove(newRotation)) {
            maxWidth = 3;
            rotation++;
        }
    } else if (rotation == 2) {
        try {
            newRotation = getPositionThree();
        } catch (...) {
            return;
        }
        if (isValidMove(newRotation)) {
            maxWidth = 2;
            rotation++;
        }
    } else if (rotation == 3) {
        if (bottomLeft->getRow() + 3 > 10) {
            return; // can't rotate
        }
        try {
            newRotation = getPositionZero();
        } catch (...) {
            return;
        }
        if (isValidMove(newRotation)) {
            maxWidth = 3;
            rotation = 0;
        }
    }
    replaceCells(newRotation, "T");
}

void TBlock::counterclockwise() {
    vector<Cell *> newRotation;
    if (rotation == 0) {
        try {
            newRotation = getPositionThree();
        } catch (...) {
            return;
        }
        if (isValidMove(newRotation)) {
            maxWidth = 2;
            rotation = 3;
        }
    } else if (rotation == 1) {
        if (bottomLeft->getRow() + 3 > 10) {
            return; // can't rotate
        }
        try {
            newRotation = getPositionZero();
        } catch (...) {
            return;
        }
        if (isValidMove(newRotation)) {
            maxWidth = 3;
            rotation--;
        }
    } else if (rotation == 2) {
        try {
            newRotation = getPositionOne();
        } catch (...) {
            return;
        }
        if (isValidMove(newRotation)) {
            maxWidth = 2;
            rotation--;
        }
    } else if (rotation == 3) {
        if (bottomLeft->getRow() + 3 > 10) {
            return; // can't rotate
        }
        try {
            newRotation = getPositionTwo();
        } catch (...) {
            return;
        }
        if (isValidMove(newRotation)) {
            maxWidth = 3;
            rotation--;
        }
    }
    replaceCells(newRotation, "T");
}

void TBlock::left() {
    if (bottomLeft->getCol() == 0) {
        return; // can't move left
    }
    vector<Cell *> newMovement;
    int curRow, curCol;
    for (int i = 0; i < blockCells.size(); i++) {
        curRow = blockCells[i]->getRow();
        curCol = blockCells[i]->getCol();
        newMovement.push_back(blockGrid[curRow][curCol-1]);
    }
    replaceCells(newMovement, "T");
}

void TBlock::right() {
    if (bottomLeft->getCol() + maxWidth > 10) {
        return; // can't move right
    }
    vector<Cell *> newMovement;
    int curRow, curCol;
    for (int i = 0; i < blockCells.size(); i++) {
        curRow = blockCells[i]->getRow();
        curCol = blockCells[i]->getCol();
        newMovement.push_back(blockGrid[curRow][curCol+1]);
    }
    replaceCells(newMovement, "T");
}

bool TBlock::down() {
    if (bottomLeft->getRow() == 17) {
        return false; // can't move down, at bottom row
    }
    vector<Cell *> newMovement;
    int curRow, curCol;
    for (int i = 0; i < blockCells.size(); i++) {
        curRow = blockCells[i]->getRow();
        curCol = blockCells[i]->getCol();
        newMovement.push_back(blockGrid[curRow+1][curCol]);
    }
    return replaceCells(newMovement, "T");
}

void TBlock::drop() {
    while (down() == true) {
        continue;
    }
}

TBlock::~TBlock() {
    bottomLeft = nullptr;
    blockCells.clear();
}
