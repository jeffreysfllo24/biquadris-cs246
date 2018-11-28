#include "sblock.h"

using namespace std;

SBlock::SBlock(int levelVal){
    this->bottomLeft = nullptr;
    this->isBottom = false;
    this->rotation = 0;
    this->maxWidth = 3;
    this->level = levelVal;
}

void SBlock::init(Cell * cell, vector<vector<Cell *>> grid) {
    bottomLeft = cell;
    blockGrid = grid;
    // create pointers to cells in the currBlock
    if (didLose()) {
        throw runtime_error("Game Over");
    }
    bottomLeft->setLetter("S");
    Cell * firstCell = blockGrid[3][1];
    firstCell->setLetter("S");
    Cell * secondCell = blockGrid[2][1];
    secondCell->setLetter("S");
    Cell * thirdCell = blockGrid[2][2];
    thirdCell->setLetter("S");
    // add to vector
    blockCells.push_back(bottomLeft);
    blockCells.push_back(firstCell);
    blockCells.push_back(secondCell);
    blockCells.push_back(thirdCell);
}

bool SBlock::didLose() {
    if (bottomLeft->isFilled() || blockGrid[3][1]->isFilled() || blockGrid[2][1]->isFilled() || blockGrid[2][2]->isFilled()) {
        return true;
    }
    return false;
}

string SBlock::getType() const {
    return "S";
}

Cell * SBlock::getBottomLeft() const {
    return bottomLeft;
}

vector<Cell *> SBlock::getBlockCells() const {
    return blockCells;
}

bool SBlock::isValidMove(vector<Cell *> newBlockCells) const {
    for (int i = 0; i < blockCells.size(); i++) {
        blockCells[i]->setLetter(""); // temporarily set old currBlock cells to empty letter
    }
    for (int i = 0; i < newBlockCells.size(); i++) {
        if (newBlockCells[i]->isFilled()) { // check if cell is already occupied by another currBlock
            for (int i = 0; i < blockCells.size(); i++) {
                blockCells[i]->setLetter("S"); // temporarily set old currBlock cells to empty letter
            }
            return false;
        }
    }
    return true; // newBlockCells does not overlap any existing blocks
}

bool SBlock::replaceCells(vector<Cell *> cells, string letter) {
    if (isValidMove(cells)) {
        for (int i = 0; i < blockCells.size(); i++) {
            cells[i]->setLetter(letter);
        }
        if (rotation == 1 || rotation == 3) {
            int firstRow = cells[0]->getRow();
            int firstCol = cells[0]->getCol();
            bottomLeft = blockGrid[firstRow][firstCol-1];
        } else if (rotation == 0 || rotation == 2) {
            bottomLeft = cells[0];
        }
        blockCells.clear(); // remove all past cells from vector
        blockCells = cells; // reassign vector to new cells
        return true;
    }
    return false;
}

vector<Cell *> SBlock::getPositionZero() {
    int bottomLeftRow = bottomLeft->getRow();
    int bottomLeftCol = bottomLeft->getCol();
    vector<Cell *> tempCells;
    // add new rotation to tempCells
    tempCells.push_back(bottomLeft);
    tempCells.push_back(blockGrid[bottomLeftRow][bottomLeftCol+1]);
    tempCells.push_back(blockGrid[bottomLeftRow-1][bottomLeftCol+1]);
    tempCells.push_back(blockGrid[bottomLeftRow-1][bottomLeftCol+2]);
    return tempCells;
}

vector<Cell *> SBlock::getPositionOne() {
    int bottomLeftRow = bottomLeft->getRow();
    int bottomLeftCol = bottomLeft->getCol();
    vector<Cell *> tempCells;
    // add new rotation to tempCells
    tempCells.push_back(blockGrid[bottomLeftRow][bottomLeftCol+1]);
    tempCells.push_back(blockGrid[bottomLeftRow-1][bottomLeftCol]);
    tempCells.push_back(blockGrid[bottomLeftRow-1][bottomLeftCol+1]);
    tempCells.push_back(blockGrid[bottomLeftRow-2][bottomLeftCol]);
    return tempCells;
}

void SBlock::clockwise(int dropAmount) {
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
        if (bottomLeft->getCol() + 3 > 10) {
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
    if (replaceCells(newRotation, "S")) down(dropAmount);
}

void SBlock::counterclockwise(int dropAmount) {
    clockwise(dropAmount);
}

void SBlock::left(int dropAmount) {
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
    if (replaceCells(newMovement, "S")) down(dropAmount);
}

void SBlock::right(int dropAmount) {
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
    if (replaceCells(newMovement, "S")) down(dropAmount);
}

bool SBlock::down(int dropAmount) {
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
        if (replaceCells(newMovement, "S")) continue;
        else return false;
    }
    return true;
}

void SBlock::drop() {
    while (down() == true) {
        continue;
    }
}

SBlock::~SBlock() {
    bottomLeft = nullptr;
    for(int i = 0; i < blockCells.size();++i){
        blockCells[i]->setLetter("");
    }
    blockCells.clear();
}
