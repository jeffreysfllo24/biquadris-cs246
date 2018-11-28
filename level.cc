#include "level.h"
#include "iblock.h"
#include "jblock.h"
#include "lblock.h"
#include "oblock.h"
#include "sblock.h"
#include "tblock.h"
#include "zblock.h"
using namespace std;

Block * Level::createSpecificBlock(char blockChar, int level) {
    if (blockChar == 'I') {
        return new IBlock{level};
    } else if (blockChar == 'J') {
        return new JBlock{level};
    } else if (blockChar == 'L') {
        return new LBlock{level};
    } else if (blockChar == 'O') {
        return new OBlock{level};
    } else if (blockChar == 'S') {
        return new SBlock{level};
    } else if (blockChar == 'T') {
        return new TBlock{level};
    } else if (blockChar == 'Z') {
        return new ZBlock{level};
    } else {
        return nullptr;
    }
}


void Level::norandom(std::string) {
    // empty implementation
}

void Level::random() {
    // empty implementation
}

Level::~Level() = default;
