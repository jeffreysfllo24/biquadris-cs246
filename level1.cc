#include <cstdlib>
#include "level1.h"
#include "iblock.h"
#include "jblock.h"
#include "lblock.h"
#include "oblock.h"
#include "sblock.h"
#include "tblock.h"
#include "zblock.h"

char Level1::generateRandom() {
    int r = rand() % 12;

    if (r < 2) {
        return 'I';
    } else if (r < 4) {
        return 'J';
    } else if (r < 6) {
        return 'L';
    } else if (r < 8) {
        return 'O';
    } else if (r < 9) {
        return 'S';
    } else if (r < 11) {
        return 'T';
    } else { // if (r < 12) {
        return 'Z';
    }
}

Level1::Level1(char nextBlock, bool providedBlock) {
    if (providedBlock) {
        this->nextBlock = nextBlock;
    } else {
        this->nextBlock = generateRandom();
    }
}

Block * Level1::generateBlock() {
    Block * newBlock = createSpecificBlock(nextBlock);

    nextBlock = generateRandom();

    return newBlock;
}

Block * Level1::createSpecificBlock(char blockChar) {
    if (blockChar == 'I') {
        return new IBlock(1);
    } else if (blockChar == 'J') {
        return new JBlock(1);
    } else if (blockChar == 'L') {
        return new LBlock(1);
    } else if (blockChar == 'O') {
        return new OBlock(1);
    } else if (blockChar == 'S') {
        return new SBlock(1);
    } else if (blockChar == 'T') {
        return new TBlock(1);
    } else if (blockChar == 'Z') {
        return new ZBlock(1);
    } else {
        return nullptr;
    }
}
