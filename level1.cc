#include <cstdlib>

#include "level1.h"

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

Level1::Level1() = default;

Block * Level1::generateBlock() {
    Block * newBlock = createSpecificBlock(generateRandom(), 1);

    return newBlock;
}

void Level1::setSeed(int newSeed){
    seed = newSeed;
    srand(seed);
}
