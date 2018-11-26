#include "level1.h"
#include "iblock.h"
#include "oblock.h"
#include "tblock.h"

char generateRandom() {
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

char Level1::getNextBlock() {
    return nextBlock;
}
