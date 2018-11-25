#include "oblock.h"

using namespace std;

OBlock::OBlock() : bottomLeft{nullptr}, isBottom{false}, rotation{0}, maxWidth{2} {}

void OBlock::init(Cell * cell, vector<vector<Cell *>> grid) {
    bottomLeft = cell;
    blockGrid = grid;
    // create pointers to cells in the block
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

string OBlock::getType() const {
    return "O";
}

Cell * OBlock::getBottomLeft() const {
    return bottomLeft;
}

bool OBlock::isValidMove(vector<Cell *> newBlockCells) const {
    for (int i = 0; i < blockCells.size(); i++) {
        blockCells[i]->setLetter(""); // temporarily set old block cells to empty letter
    }
    for (int i = 0; i < newBlockCells.size(); i++) {
        if (newBlockCells[i]->isFilled()) { // check if cell is already occupied by another block
            for (int i = 0; i < blockCells.size(); i++) {
                blockCells[i]->setLetter("O"); // temporarily set old block cells to empty letter
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

void OBlock::clockwise() {
    // do nothing, rotation results in exact same position
}

void OBlock::counterclockwise() {
    // do nothing
}

void OBlock::left() {
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
    replaceCells(newMovement, "O");
}

void OBlock::right() {
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
    replaceCells(newMovement, "O");
}

bool OBlock::down() {
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
    return replaceCells(newMovement, "O");
}

void OBlock::drop() {
    while (down() == true) {
        continue;
    }
}

OBlock::~OBlock() {
    bottomLeft = nullptr;
    blockCells.clear();
}
