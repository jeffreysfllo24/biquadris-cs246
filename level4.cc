#include <cstdlib>
#include <fstream>
#include <string>

#include "level4.h"
#include "iblock.h"
#include "jblock.h"
#include "lblock.h"
#include "oblock.h"
#include "sblock.h"
#include "tblock.h"
#include "zblock.h"

using namespace std;

char Level4::generateRandom() {
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

Level4::Level4(char nextBlock, bool providedBlock): useSequence{false} {
    if (providedBlock) {
        this->nextBlock = nextBlock;
    } else {
        this->nextBlock = generateRandom();
    }
}

Block * Level4::generateBlock() {
    Block * newBlock = createSpecificBlock(nextBlock);

    if (useSequence) {
        index++;
        if (index >= sequence.size()) {
            index = 0;
        }
        nextBlock = sequence[index];
    } else {
        nextBlock = generateRandom();
    }

    return newBlock;
}

void Level4::norandom(string filename) {
    useSequence = true;

    ifstream file{filename};

    string letter;
    while (file >> letter) {
        sequence.push_back(letter[0]); // Take the first index of each string to get the character
    }
}

void Level4::random() {
    useSequence = false;
    index = 0;
    sequence.clear();
}
Block * Level4::createSpecificBlock(char blockChar) {
    if (blockChar == 'I') {
        return new IBlock(4);
    } else if (blockChar == 'J') {
        return new JBlock(4);
    } else if (blockChar == 'L') {
        return new LBlock(4);
    } else if (blockChar == 'O') {
        return new OBlock(4);
    } else if (blockChar == 'S') {
        return new SBlock(4);
    } else if (blockChar == 'T') {
        return new TBlock(4);
    } else if (blockChar == 'Z') {
        return new ZBlock(4);
    } else {
        return nullptr;
    }
}
