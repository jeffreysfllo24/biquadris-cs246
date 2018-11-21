#include "iblock.h"

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
    return 'i';
}

bool IBlock::isValidMove(std::vector<Cell *> tempBlockCells) const {}

void IBlock::clockwise() {}

void IBlock::counterclockwise() {}

void IBlock::left() {}

void IBlock::right() {}

void IBlock::down() {}

void IBlock::drop() {}

IBlock::~IBlock() {}
