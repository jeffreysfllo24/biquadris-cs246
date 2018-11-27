#include <cstdlib>

#include "level3.h"

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
