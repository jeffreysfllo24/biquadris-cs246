#include "level.h"
#include "iblock.h"
#include "jblock.h"
#include "lblock.h"
#include "oblock.h"
#include "sblock.h"
#include "tblock.h"
#include "zblock.h"

Block * Level::createSpecificBlock(char blockChar) {
    if (nextBlock == 'I') {
        return new IBlock;
    } else if (nextBlock == 'J') {
        return new JBlock;
    } else if (nextBlock == 'L') {
        return new LBlock;
    } else if (nextBlock == 'O') {
        return new OBlock;
    } else if (nextBlock == 'S') {
        return new SBlock;
    } else if (nextBlock == 'T') {
        return new TBlock;
    } else if (nextBlock == 'Z') {
        return new ZBlock;
    } else {
        return nullptr;
    }
}

char Level::getNextBlock() {
    return nextBlock;
}

void Level::norandom(std::string) {
    // empty implementation
}

void Level::random() {
    // empty implementation
}

Level::~Level() = default;
