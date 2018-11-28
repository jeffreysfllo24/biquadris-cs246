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

Level2::Level2() = default;

Block * Level2::generateBlock() {
    Block * newBlock = createSpecificBlock(generateRandom(), 2);

    return newBlock;
}
