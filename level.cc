#include "level.h"
#include "iblock.h"
#include "jblock.h"
#include "lblock.h"
#include "oblock.h"
#include "sblock.h"
#include "tblock.h"
#include "zblock.h"
using namespace std;

//Block * Level::createSpecificBlock(char blockChar) {
//    if (blockChar == 'I') {
//        return new IBlock;
//    } else if (blockChar == 'J') {
//        return new JBlock;
//    } else if (blockChar == 'L') {
//        return new LBlock;
//    } else if (blockChar == 'O') {
//        return new OBlock;
//    } else if (blockChar == 'S') {
//        return new SBlock;
//    } else if (blockChar == 'T') {
//        return new TBlock;
//    } else if (blockChar == 'Z') {
//        return new ZBlock;
//    } else {
//        return nullptr;
//    }
//}

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
