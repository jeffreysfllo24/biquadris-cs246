#include "level.h"
#include "iblock.h"
#include "oblock.h"
#include "tblock.h"

Block * Level::createSpecificBlock(char blockChar) {
//    if (sequence[index] == 'I') {
//        return new IBlock;
//    } else if (sequence[index] == 'J') {
//        return new JBlock;
//    } else if (sequence[index] == 'L') {
//        return new LBlock;
//    } else if (sequence[index] == 'O') {
//        return new OBlock;
//    } else if (sequence[index] == 'S') {
//        return new SBlock;
//    } else if (sequence[index] == 'T') {
//        return new TBlock;
//    } else  { if (sequence[index] == 'Z')
//        return new ZBlock;
//    }
    return new IBlock;
}

Level::~Level() = default;
