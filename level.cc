#include "level.h"
#include "iblock.h"
#include "oblock.h"
#include "tblock.h"

Block * Level::createSpecificBlock(char blockChar) {
//    if (nextBlock == 'I') {
//        return new IBlock;
//    } else if (nextBlock == 'J') {
//        return new JBlock;
//    } else if (nextBlock == 'L') {
//        return new LBlock;
//    } else if (nextBlock == 'O') {
//        return new OBlock;
//    } else if (nextBlock == 'S') {
//        return new SBlock;
//    } else if (nextBlock == 'T') {
//        return new TBlock;
//    } else if (nextBlock == 'Z') {
//        return new ZBlock;
//    } else {
//        return nullptr;
//    }
    return new IBlock;
}

Level::~Level() = default;
