#include "jblock.h"

using namespace std;

JBlock::JBlock(){
    this->bottomLeft = nullptr;
    this->isBottom = false;
    this->rotation = 0;
    this->maxWidth = 3;
    this->level = 0;
}

void JBlock::init(Cell * cell, vector<vector<Cell *>> grid) {
    bottomLeft = cell;
    blockGrid = grid;
    // create pointers to cells in the block
    if (didLose()) {
        throw runtime_error("Game Over");
    }
    bottomLeft->setLetter("J");
    Cell * firstCell = blockGrid[3][1];
    firstCell->setLetter("J");
    Cell * secondCell = blockGrid[3][2];
    secondCell->setLetter("J");
    Cell * thirdCell = blockGrid[2][0];
    thirdCell->setLetter("J");
    // add to vector
    blockCells.push_back(bottomLeft);
    blockCells.push_back(firstCell);
    blockCells.push_back(secondCell);
    blockCells.push_back(thirdCell);
}

bool JBlock::didLose() {
    if (bottomLeft->isFilled() || blockGrid[3][1]->isFilled() || blockGrid[3][2]->isFilled() || blockGrid[2][0]->isFilled()) {
        return true;
    }
    return false;
}

string JBlock::getType() const {
    return "J";
}

Cell * JBlock::getBottomLeft() const {
    return bottomLeft;
}

vector<Cell *> JBlock::getBlockCells() const {
    return blockCells;
}

bool JBlock::isValidMove(vector<Cell *> newBlockCells) const {
    for (int i = 0; i < blockCells.size(); i++) {
        blockCells[i]->setLetter(""); // temporarily set old block cells to empty letter
    }
    for (int i = 0; i < newBlockCells.size(); i++) {
        if (newBlockCells[i]->isFilled()) { // check if cell is already occupied by another block
            for (int i = 0; i < blockCells.size(); i++) {
                blockCells[i]->setLetter("J"); // temporarily set old block cells to empty letter
            }
            return false;
        }
    }
    return true; // newBlockCells does not overlap any existing blocks
}

bool JBlock::replaceCells(vector<Cell *> cells, string letter) {
    if (isValidMove(cells)) {
        for (int i = 0; i < blockCells.size(); i++) {
            cells[i]->setLetter(letter);
        }
        if (rotation == 2) {
            int firstRow = cells[0]->getRow();
            int firstCol = cells[0]->getCol();
            bottomLeft = blockGrid[firstRow][firstCol-2];
        } else if (rotation == 0 || rotation == 1 || rotation == 3) {
            bottomLeft = cells[0];
        }
        blockCells.clear(); // remove all past cells from vector
        blockCells = cells; // reassign vector to new cells
        return true;
    }
    return false;
}

vector<Cell *> JBlock::getPositionZero() {
    int bottomLeftRow = bottomLeft->getRow();
    int bottomLeftCol = bottomLeft->getCol();
    vector<Cell *> tempCells;
    // add new rotation to tempCells
    tempCells.push_back(bottomLeft);
    tempCells.push_back(blockGrid[bottomLeftRow][bottomLeftCol+1]);
    tempCells.push_back(blockGrid[bottomLeftRow][bottomLeftCol+2]);
    tempCells.push_back(blockGrid[bottomLeftRow-1][bottomLeftCol]);
    return tempCells;
}

vector<Cell *> JBlock::getPositionOne() {
    int bottomLeftRow = bottomLeft->getRow();
    int bottomLeftCol = bottomLeft->getCol();
    vector<Cell *> tempCells;
    // add new rotation to tempCells
    tempCells.push_back(bottomLeft);
    tempCells.push_back(blockGrid[bottomLeftRow-1][bottomLeftCol]);
    tempCells.push_back(blockGrid[bottomLeftRow-2][bottomLeftCol]);
    tempCells.push_back(blockGrid[bottomLeftRow-2][bottomLeftCol+1]);
    return tempCells;
}

vector<Cell *> JBlock::getPositionTwo() {
    int bottomLeftRow = bottomLeft->getRow();
    int bottomLeftCol = bottomLeft->getCol();
    vector<Cell *> tempCells;
    // add new rotation to tempCells
    tempCells.push_back(blockGrid[bottomLeftRow][bottomLeftCol+2]);
    tempCells.push_back(blockGrid[bottomLeftRow-1][bottomLeftCol]);
    tempCells.push_back(blockGrid[bottomLeftRow-1][bottomLeftCol+1]);
    tempCells.push_back(blockGrid[bottomLeftRow-1][bottomLeftCol+2]);
    return tempCells;
}

vector<Cell *> JBlock::getPositionThree() {
    int bottomLeftRow = bottomLeft->getRow();
    int bottomLeftCol = bottomLeft->getCol();
    vector<Cell *> tempCells;
    // add new rotation to tempCells
    tempCells.push_back(bottomLeft);
    tempCells.push_back(blockGrid[bottomLeftRow][bottomLeftCol+1]);
    tempCells.push_back(blockGrid[bottomLeftRow-1][bottomLeftCol+1]);
    tempCells.push_back(blockGrid[bottomLeftRow-2][bottomLeftCol+1]);
    return tempCells;
}

void JBlock::clockwise(int dropAmount) {
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
    if (replaceCells(newRotation, "J")) down(dropAmount);
}

void JBlock::counterclockwise(int dropAmount) {
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
    if(replaceCells(newRotation, "J")) down(dropAmount);
}

void JBlock::left(int dropAmount) {
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
    if (replaceCells(newMovement, "J")) down(dropAmount);
}

void JBlock::right(int dropAmount) {
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
    if (replaceCells(newMovement, "J")) down(dropAmount);
}

bool JBlock::down(int dropAmount) {
    for (int i = 0; i < dropAmount; i++) {
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
        if (replaceCells(newMovement, "J")) continue;
        else return false;
    }
    return true;
}

void JBlock::drop() {
    while (down() == true) {
        continue;
    }
}

JBlock::~JBlock() {
    bottomLeft = nullptr;
    blockCells.clear();
}
