#include "zblock.h"
#include "block.h"

using namespace std;

ZBlock::ZBlock(){
     this->bottomLeft = nullptr;
     this->isBottom = false;
     this->rotation = 0;
     this->maxWidth = 3;
    this->level = 0;
}

void ZBlock::init(Cell * cell, vector<vector<Cell *>> grid) {
    bottomLeft = cell;
    blockGrid = grid;
    // create pointers to cells in the block
    if (didLose()) {
        throw runtime_error("Game Over");
    }
    Cell * zeroCell = blockGrid[3][1];
    zeroCell->setLetter("Z");
    Cell * firstCell = blockGrid[3][2];
    firstCell->setLetter("Z");
    Cell * secondCell = blockGrid[2][0];
    secondCell->setLetter("Z");
    Cell * thirdCell = blockGrid[2][1];
    thirdCell->setLetter("Z");
    // add to vector
    blockCells.push_back(zeroCell);
    blockCells.push_back(firstCell);
    blockCells.push_back(secondCell);
    blockCells.push_back(thirdCell);
}

bool ZBlock::didLose() {
    if (blockGrid[3][1]->isFilled() || blockGrid[3][2]->isFilled() || blockGrid[2][0]->isFilled() || blockGrid[2][1]->isFilled()) {
        return true;
    }
    return false;
}

string ZBlock::getType() const {
    return "Z";
}

Cell * ZBlock::getBottomLeft() const {
    return bottomLeft;
}

vector<Cell *> ZBlock::getBlockCells() const {
    return blockCells;
}

bool ZBlock::isValidMove(vector<Cell *> newBlockCells) const {
    for (int i = 0; i < blockCells.size(); i++) {
        blockCells[i]->setLetter(""); // temporarily set old block cells to empty letter
    }
    for (int i = 0; i < newBlockCells.size(); i++) {
        if (newBlockCells[i]->isFilled()) { // check if cell is already occupied by another block
            for (int i = 0; i < blockCells.size(); i++) {
                blockCells[i]->setLetter("Z"); // temporarily set old block cells to empty letter
            }
            return false;
        }
    }
    return true; // newBlockCells does not overlap any existing blocks
}

bool ZBlock::replaceCells(vector<Cell *> cells, string letter) {
    if (isValidMove(cells)) {
        for (int i = 0; i < blockCells.size(); i++) {
            cells[i]->setLetter(letter);
        }
        if (rotation == 0 || rotation == 2) {
            int firstRow = cells[0]->getRow();
            int firstCol = cells[0]->getCol();
            bottomLeft = blockGrid[firstRow][firstCol-1];
        } else if (rotation == 1 || rotation == 3) {
            bottomLeft = cells[0];
        }
        blockCells.clear(); // remove all past cells from vector
        blockCells = cells; // reassign vector to new cells
        return true;
    }
    return false;
}

vector<Cell *> ZBlock::getPositionZero() {
    int bottomLeftRow = bottomLeft->getRow();
    int bottomLeftCol = bottomLeft->getCol();
    vector<Cell *> tempCells;
    // add new rotation to tempCells
    tempCells.push_back(blockGrid[bottomLeftRow][bottomLeftCol+1]);
    tempCells.push_back(blockGrid[bottomLeftRow][bottomLeftCol+2]);
    tempCells.push_back(blockGrid[bottomLeftRow-1][bottomLeftCol]);
    tempCells.push_back(blockGrid[bottomLeftRow-1][bottomLeftCol+1]);
    return tempCells;
}

vector<Cell *> ZBlock::getPositionOne() {
    int bottomLeftRow = bottomLeft->getRow();
    int bottomLeftCol = bottomLeft->getCol();
    vector<Cell *> tempCells;
    // add new rotation to tempCells
    tempCells.push_back(bottomLeft);
    tempCells.push_back(blockGrid[bottomLeftRow-1][bottomLeftCol]);
    tempCells.push_back(blockGrid[bottomLeftRow-1][bottomLeftCol+1]);
    tempCells.push_back(blockGrid[bottomLeftRow-2][bottomLeftCol+1]);
    return tempCells;
}

void ZBlock::clockwise() {
    vector<Cell *> newRotation;
    if (rotation == 0 || rotation == 2) { // same rotation for positions 0 and 2
        try {
            newRotation = getPositionOne();
        } catch (...) {
            return;
        }
        if (isValidMove(newRotation)) {
            maxWidth = 2;
            rotation++;
        }
    } else if (rotation == 1 || rotation == 3) { // same rotation for positions 1 and 3
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
            if (rotation == 1) rotation++;
            else rotation = 0;
        }
    }
    replaceCells(newRotation, "Z");
}

void ZBlock::counterclockwise() {
    clockwise();
}

void ZBlock::left() {
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
    replaceCells(newMovement, "Z");
}

void ZBlock::right() {
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
    replaceCells(newMovement, "Z");
}

bool ZBlock::down() {
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
    return replaceCells(newMovement, "Z");
}

void ZBlock::drop() {
    while (down() == true) {
        continue;
    }
}

ZBlock::~ZBlock() {
    bottomLeft = nullptr;
    blockCells.clear();
}
