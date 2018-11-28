#include "oblock.h"

using namespace std;

OBlock::OBlock(int levelVal){
    this->bottomLeft = nullptr;
    this->isBottom = false;
    this->rotation = 0;
    this->maxWidth = 2;
    this->level = levelVal;
}

void OBlock::init(Cell * cell, vector<vector<Cell *>> grid) {
    bottomLeft = cell;
    blockGrid = grid;
    // create pointers to cells in the currBlock
    if (didLose()) {
        throw runtime_error("Game Over");
    }
    bottomLeft->setLetter("O");
    Cell * firstCell = blockGrid[3][1];
    firstCell->setLetter("O");
    Cell * secondCell = blockGrid[2][0];
    secondCell->setLetter("O");
    Cell * thirdCell = blockGrid[2][1];
    thirdCell->setLetter("O");
    // add to vector
    blockCells.push_back(bottomLeft);
    blockCells.push_back(firstCell);
    blockCells.push_back(secondCell);
    blockCells.push_back(thirdCell);
}

bool OBlock::didLose(){
    if (bottomLeft->isFilled() || blockGrid[3][1]->isFilled() || blockGrid[2][0]->isFilled() || blockGrid[2][1]->isFilled()) {
        return true;
    }
    return false;
}

string OBlock::getType() const {
    return "O";
}

Cell * OBlock::getBottomLeft() const {
    return bottomLeft;
}

vector<Cell *> OBlock::getBlockCells() const {
    return blockCells;
}

bool OBlock::isValidMove(vector<Cell *> newBlockCells) const {
    for (int i = 0; i < blockCells.size(); i++) {
        blockCells[i]->setLetter(""); // temporarily set old currBlock cells to empty letter
    }
    for (int i = 0; i < newBlockCells.size(); i++) {
        if (newBlockCells[i]->isFilled()) { // check if cell is already occupied by another currBlock
            for (int i = 0; i < blockCells.size(); i++) {
                blockCells[i]->setLetter("O"); // temporarily set old currBlock cells to empty letter
            }
            return false;
        }
    }
    return true; // newBlockCells does not overlap any existing blocks
}

bool OBlock::replaceCells(vector<Cell *> cells, string letter) {
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

void OBlock::clockwise(int dropAmount) {
    // rotation results in exact same position
    down(dropAmount);
}

void OBlock::counterclockwise(int dropAmount) {
    // rotation results in exact same position
    down(dropAmount);
}

void OBlock::left(int dropAmount) {
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
    if (replaceCells(newMovement, "O")) down(dropAmount);
}

void OBlock::right(int dropAmount) {
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
    if (replaceCells(newMovement, "O")) down(dropAmount);
}

bool OBlock::down(int dropAmount) {
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
        if (replaceCells(newMovement, "O")) continue;
        else return false;
    }
    return true;
}

void OBlock::drop() {
    while (down() == true) {
        continue;
    }
}

OBlock::~OBlock() {
    bottomLeft = nullptr;
    for(int i = 0; i < blockCells.size();++i){
        blockCells[i]->setLetter("");
    }
    blockCells.clear();
}
