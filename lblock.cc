#include "lblock.h"

using namespace std;

LBlock::LBlock(){
    this->bottomLeft = nullptr;
    this->isBottom = false;
    this->rotation = 0;
    this->maxWidth = 3;
    this->level = 0;
}

void LBlock::init(Cell * cell, vector<vector<Cell *>> grid) {
    bottomLeft = cell;
    blockGrid = grid;
    // create pointers to cells in the block
    if (didLose()) {
        throw runtime_error("Game Over");
    }
    bottomLeft->setLetter("L");
    Cell * firstCell = blockGrid[3][1];
    firstCell->setLetter("L");
    Cell * secondCell = blockGrid[3][2];
    secondCell->setLetter("L");
    Cell * thirdCell = blockGrid[2][2];
    thirdCell->setLetter("L");
    // add to vector
    blockCells.push_back(bottomLeft);
    blockCells.push_back(firstCell);
    blockCells.push_back(secondCell);
    blockCells.push_back(thirdCell);
}

bool LBlock::didLose() {
    if (bottomLeft->isFilled() || blockGrid[3][1]->isFilled() || blockGrid[3][2]->isFilled() || blockGrid[2][2]->isFilled()) {
        return true;
    }
    return false;
}

string LBlock::getType() const {
    return "L";
}

Cell * LBlock::getBottomLeft() const {
    return bottomLeft;
}

vector<Cell *> LBlock::getBlockCells() const {
    return blockCells;
}

bool LBlock::isValidMove(vector<Cell *> newBlockCells) const {
    for (int i = 0; i < blockCells.size(); i++) {
        blockCells[i]->setLetter(""); // temporarily set old block cells to empty letter
    }
    for (int i = 0; i < newBlockCells.size(); i++) {
        if (newBlockCells[i]->isFilled()) { // check if cell is already occupied by another block
            for (int i = 0; i < blockCells.size(); i++) {
                blockCells[i]->setLetter("L"); // temporarily set old block cells to empty letter
            }
            return false;
        }
    }
    return true; // newBlockCells does not overlap any existing blocks
}

bool LBlock::replaceCells(vector<Cell *> cells, string letter) {
    if (isValidMove(cells)) {
        for (int i = 0; i < blockCells.size(); i++) {
            cells[i]->setLetter(letter);
        }
        if (rotation == 3) {
            int firstRow = cells[0]->getRow();
            int firstCol = cells[0]->getCol();
            bottomLeft = blockGrid[firstRow][firstCol-1];
        } else if (rotation == 0 || rotation == 1 || rotation == 2) {
            bottomLeft = cells[0];
        }
        blockCells.clear(); // remove all past cells from vector
        blockCells = cells; // reassign vector to new cells
        return true;
    }
    return false;
}

vector<Cell *> LBlock::getPositionZero() {
    int bottomLeftRow = bottomLeft->getRow();
    int bottomLeftCol = bottomLeft->getCol();
    vector<Cell *> tempCells;
    // add new rotation to tempCells
    tempCells.push_back(bottomLeft);
    tempCells.push_back(blockGrid[bottomLeftRow][bottomLeftCol+1]);
    tempCells.push_back(blockGrid[bottomLeftRow][bottomLeftCol+2]);
    tempCells.push_back(blockGrid[bottomLeftRow-1][bottomLeftCol+2]);
    return tempCells;
}

vector<Cell *> LBlock::getPositionOne() {
    int bottomLeftRow = bottomLeft->getRow();
    int bottomLeftCol = bottomLeft->getCol();
    vector<Cell *> tempCells;
    // add new rotation to tempCells
    tempCells.push_back(bottomLeft);
    tempCells.push_back(blockGrid[bottomLeftRow][bottomLeftCol+1]);
    tempCells.push_back(blockGrid[bottomLeftRow-1][bottomLeftCol]);
    tempCells.push_back(blockGrid[bottomLeftRow-2][bottomLeftCol]);
    return tempCells;
}

vector<Cell *> LBlock::getPositionTwo() {
    int bottomLeftRow = bottomLeft->getRow();
    int bottomLeftCol = bottomLeft->getCol();
    vector<Cell *> tempCells;
    // add new rotation to tempCells
    tempCells.push_back(bottomLeft);
    tempCells.push_back(blockGrid[bottomLeftRow-1][bottomLeftCol]);
    tempCells.push_back(blockGrid[bottomLeftRow-1][bottomLeftCol+1]);
    tempCells.push_back(blockGrid[bottomLeftRow-1][bottomLeftCol+2]);
    return tempCells;
}

vector<Cell *> LBlock::getPositionThree() {
    int bottomLeftRow = bottomLeft->getRow();
    int bottomLeftCol = bottomLeft->getCol();
    vector<Cell *> tempCells;
    // add new rotation to tempCells
    tempCells.push_back(blockGrid[bottomLeftRow][bottomLeftCol+1]);
    tempCells.push_back(blockGrid[bottomLeftRow-1][bottomLeftCol+1]);
    tempCells.push_back(blockGrid[bottomLeftRow-2][bottomLeftCol]);
    tempCells.push_back(blockGrid[bottomLeftRow-2][bottomLeftCol+1]);
    return tempCells;
}

void LBlock::clockwise() {
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
    replaceCells(newRotation, "L");
}

void LBlock::counterclockwise() {
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
    replaceCells(newRotation, "L");
}

void LBlock::left() {
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
    replaceCells(newMovement, "L");
}

void LBlock::right() {
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
    replaceCells(newMovement, "L");
}

bool LBlock::down() {
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
    return replaceCells(newMovement, "L");
}

void LBlock::drop() {
    while (down() == true) {
        continue;
    }
}

LBlock::~LBlock() {
    bottomLeft = nullptr;
    blockCells.clear();
}
