#include "starblock.h"

using namespace std;

StarBlock::StarBlock(int levelVal){
    this->bottomLeft = nullptr;
    this->isBottom = false;
    this->rotation = 0;
    this->maxWidth = 4;
    this->level = levelVal;
}

void StarBlock::init(Cell * cell, vector<vector<Cell *>> grid) {
    bottomLeft = cell;
    blockGrid = grid;
    if (didLose()) {
        throw runtime_error("Game Over");
    }
    // create pointers to cells in the currBlock
    bottomLeft->setLetter("*");
    // add to vector
    blockCells.push_back(bottomLeft);
}

bool StarBlock::didLose(){
    return bottomLeft->isFilled();
}

string StarBlock::getType() const {
    return "*";
}

Cell * StarBlock::getBottomLeft() const {
    return bottomLeft;
}

vector<Cell *> StarBlock::getBlockCells() const {
    return blockCells;
}

bool StarBlock::isValidMove(vector<Cell *> newBlockCells) const {
    for (int i = 0; i < blockCells.size(); i++) {
        blockCells[i]->setLetter(""); // temporarily set old currBlock cells to empty letter
    }
    for (int i = 0; i < newBlockCells.size(); i++) {
        if (newBlockCells[i]->isFilled()) { // check if cell is already occupied by another currBlock
            for (int i = 0; i < blockCells.size(); i++) {
                blockCells[i]->setLetter("*"); // temporarily set old currBlock cells to empty letter
            }
            return false;
        }
    }
    return true; // newBlockCells does not overlap any existing blocks
}

bool StarBlock::replaceCells(vector<Cell *> cells, string letter) {
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

void StarBlock::clockwise(int) {
    // Do nothing
}

void StarBlock::counterclockwise(int) {
    // Do nothing
}

void StarBlock::left(int) {
    // Do nothing
}

void StarBlock::right(int) {
    // Do nothing
}

bool StarBlock::down(int dropAmount) {
    for (int i = 0; i < dropAmount; i++) {
        if (bottomLeft->getRow() == 17) {
            return false; // can't move down, at bottom row
        }
        vector<Cell *> newMovement;
        int curRow, curCol;
        for (int j = 0; j < blockCells.size(); j++) {
            curRow = blockCells[j]->getRow();
            curCol = blockCells[j]->getCol();
            newMovement.push_back(blockGrid[curRow+1][curCol]);
        }
        if (replaceCells(newMovement, "*")) continue;
        else return false;
    }
    return true;
}

void StarBlock::drop() {
    while (down());
}

StarBlock::~StarBlock() {
    bottomLeft = nullptr;
    for(int i = 0; i < blockCells.size();++i){
        blockCells[i]->setLetter("");
    }
    blockCells.clear();
}
