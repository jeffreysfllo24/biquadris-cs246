#include "iblock.h"

using namespace std;

IBlock::IBlock() : bottomLeft{nullptr}, isBottom{false}, rotation{0}, maxWidth{4},level(0) {}

void IBlock::init(Cell * cell, vector<vector<Cell *>> grid) {
    bottomLeft = cell;
    blockGrid = grid;
    if (didLose()) {
        throw runtime_error("Game Over");
    }
    // create pointers to cells in the block
    bottomLeft->setLetter("I");
    Cell * firstCell = blockGrid[3][1];
    firstCell->setLetter("I");
    Cell * secondCell = blockGrid[3][2];
    secondCell->setLetter("I");
    Cell * thirdCell = blockGrid[3][3];
    thirdCell->setLetter("I");
    // add to vector
    blockCells.push_back(bottomLeft);
    blockCells.push_back(firstCell);
    blockCells.push_back(secondCell);
    blockCells.push_back(thirdCell);
}

bool IBlock::didLose(){
    if (bottomLeft->isFilled() || blockGrid[3][1]->isFilled() || blockGrid[3][2]->isFilled() || blockGrid[3][3]->isFilled()) {
        return true;
    }
    return false;
}

string IBlock::getType() const {
    return "I";
}

Cell * IBlock::getBottomLeft() const {
    return bottomLeft;
}

vector<Cell *> IBlock::getBlockCells() const {
    return blockCells;
}

bool IBlock::isValidMove(vector<Cell *> newBlockCells) const {
    for (int i = 0; i < blockCells.size(); i++) {
        blockCells[i]->setLetter(""); // temporarily set old block cells to empty letter
    }
    for (int i = 0; i < newBlockCells.size(); i++) {
        if (newBlockCells[i]->isFilled()) { // check if cell is already occupied by another block
            for (int i = 0; i < blockCells.size(); i++) {
                blockCells[i]->setLetter("I"); // temporarily set old block cells to empty letter
            }
            return false;
        }
    }
    return true; // newBlockCells does not overlap any existing blocks
}

bool IBlock::replaceCells(vector<Cell *> cells, string letter) {
    if (isValidMove(cells)) {
        for (int i = 0; i < blockCells.size(); i++) {
            cells[i]->setLetter(letter);
        }
        bottomLeft = cells[0]; // set bottomLeft
        blockCells.clear(); // remove all past cells from vector
        blockCells = cells; // reassign vector to new cells
        return true;
    }
    return false;
}

vector<Cell *> IBlock::getPositionZero() {
    int bottomLeftRow = bottomLeft->getRow();
    int bottomLeftCol = bottomLeft->getCol();
    vector<Cell *> tempCells;
    // add new rotation to tempCells
    tempCells.push_back(bottomLeft);
    tempCells.push_back(blockGrid[bottomLeftRow][bottomLeftCol+1]);
    tempCells.push_back(blockGrid[bottomLeftRow][bottomLeftCol+2]);
    tempCells.push_back(blockGrid[bottomLeftRow][bottomLeftCol+3]);
    return tempCells;
}

vector<Cell *> IBlock::getPositionOne() {
    int bottomLeftRow = bottomLeft->getRow();
    int bottomLeftCol = bottomLeft->getCol();
    vector<Cell *> tempCells;
    // add new rotation to tempCells
    tempCells.push_back(bottomLeft);
    tempCells.push_back(blockGrid[bottomLeftRow-1][bottomLeftCol]);
    tempCells.push_back(blockGrid[bottomLeftRow-2][bottomLeftCol]);
    tempCells.push_back(blockGrid[bottomLeftRow-3][bottomLeftCol]);
    return tempCells;
}

void IBlock::clockwise() {
    vector<Cell *> newRotation;
    if (rotation == 0 || rotation == 2) { // same rotation for positions 0 and 2
        try {
            newRotation = getPositionOne();
        } catch (...) {
            return;
        }
        if (isValidMove(newRotation)) {
            maxWidth = 1;
            rotation++;
        }
    } else if (rotation == 1 || rotation == 3) { // same rotation for positions 1 and 3
        if (bottomLeft->getRow() + 4 > 10) {
            return; // can't rotate
        }
        try {
            newRotation = getPositionZero();
        } catch (...) {
            return;
        }
        if (isValidMove(newRotation)) {
            maxWidth = 4;
            if (rotation == 1) rotation++;
            else rotation = 0;
        }
    }
    replaceCells(newRotation, "I");
}

void IBlock::counterclockwise() {
    clockwise();
}

void IBlock::left() {
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
    replaceCells(newMovement, "I");
}

void IBlock::right() {
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
    replaceCells(newMovement, "I");
}

bool IBlock::down() {
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
    return replaceCells(newMovement, "I");
}

void IBlock::drop() {
    while (down() == true) {
        continue;
    }
}

IBlock::~IBlock() {
    bottomLeft = nullptr;
    blockCells.clear();
}
