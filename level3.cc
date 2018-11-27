#include <cstdlib>
#include "level3.h"
#include "iblock.h"
#include "jblock.h"
#include "lblock.h"
#include "oblock.h"
#include "sblock.h"
#include "tblock.h"
#include "zblock.h"

char Level3::generateRandom() {
    int r = rand() % 9;

    if (r < 1) {
        return 'I';
    } else if (r < 2) {
        return 'J';
    } else if (r < 3) {
        return 'L';
    } else if (r < 4) {
        return 'O';
    } else if (r < 6) {
        return 'S';
    } else if (r < 7) {
        return 'T';
    } else { // if (r < 9) {
        return 'Z';
    }
}

Level3::Level3(char nextBlock, bool providedBlock) {
    if (providedBlock) {
        this->nextBlock = nextBlock;
    } else {
        this->nextBlock = generateRandom();
    }
}

Block * Level3::generateBlock() {
    Block * newBlock = createSpecificBlock(nextBlock);

    nextBlock = generateRandom();

    return newBlock;
}

Block * Level3::createSpecificBlock(char blockChar) {
    if (blockChar == 'I') {
        return new IBlock(3);
    } else if (blockChar == 'J') {
        return new JBlock(3);
    } else if (blockChar == 'L') {
        return new LBlock(3);
    } else if (blockChar == 'O') {
        return new OBlock(3);
    } else if (blockChar == 'S') {
        return new SBlock(3);
    } else if (blockChar == 'T') {
        return new TBlock(3);
    } else if (blockChar == 'Z') {
        return new ZBlock(3);
    } else {
        return nullptr;
    }
}
