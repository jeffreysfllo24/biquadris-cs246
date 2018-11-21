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

char IBlock::getBlockType() const {
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

void IBlock::clockwise() {}

void IBlock::counterclockwise() {}

void IBlock::left() {
    if (bottomLeft->getX() == 0) {
        return; // can't move left
    }
    vector<Cell *> tempCells;
    for (int i = 0; i < blockCells.size(); i++) {
        int curX = blockCells[i]->getX();
        int curY = blockCells[i]->getY();
        tempCells.push_back(blockGrid[curX-1][curY]);
    }
    if (isValidMove(tempCells)) {
        for (int i = 0; i < blockCells.size(); i++) {
            blockCells[i]->setLetter(0);
        }
        blockCells.clear();
        blockCells = tempCells;
    }
    tempCells.clear(); // don't really need
}

void IBlock::right() {}

void IBlock::down() {}

void IBlock::drop() {}

IBlock::~IBlock() {
    bottomLeft = nullptr;
    blockGrid = nullptr;
    blockCells.clear();
}
