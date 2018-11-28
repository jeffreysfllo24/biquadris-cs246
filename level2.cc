#include <cstdlib>
#include "level2.h"
#include "iblock.h"
#include "jblock.h"
#include "lblock.h"
#include "oblock.h"
#include "sblock.h"
#include "tblock.h"
#include "zblock.h"

char Level2::generateRandom() {
    int r = rand() % 7;

    if (r < 1) {
        return 'I';
    } else if (r < 2) {
        return 'J';
    } else if (r < 3) {
        return 'L';
    } else if (r < 4) {
        return 'O';
    } else if (r < 5) {
        return 'S';
    } else if (r < 6) {
        return 'T';
    } else { // if (r < 7) {
        return 'Z';
    }
}

Level2::Level2(char nextBlock, bool providedBlock) {
    if (providedBlock) {
        this->nextBlock = nextBlock;
    } else {
        this->nextBlock = generateRandom();
    }
}

Block * Level2::generateBlock() {
    Block * newBlock = createSpecificBlock(nextBlock);

    nextBlock = generateRandom();

    return newBlock;
}

Block * Level2::createSpecificBlock(char blockChar) {
    if (blockChar == 'I') {
        return new IBlock(2);
    } else if (blockChar == 'J') {
        return new JBlock(2);
    } else if (blockChar == 'L') {
        return new LBlock(2);
    } else if (blockChar == 'O') {
        return new OBlock(2);
    } else if (blockChar == 'S') {
        return new SBlock(2);
    } else if (blockChar == 'T') {
        return new TBlock(2);
    } else if (blockChar == 'Z') {
        return new ZBlock(2);
    } else {
        return nullptr;
    }
}
