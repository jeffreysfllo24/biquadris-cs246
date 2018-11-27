#include <cstdlib>
#include <fstream>
#include <string>
#include "level0.h"
#include "iblock.h"
#include "jblock.h"
#include "lblock.h"
#include "oblock.h"
#include "sblock.h"
#include "tblock.h"
#include "zblock.h"

using namespace std;

Level0::Level0(bool isPlayerOne, char nextBlock, bool providedBlock): // Add each letter from input file to a vector
    index{0} {
    string sequenceFile = isPlayerOne ? "sequence1.txt" : "sequence2.txt"; // set sequence based on player
    ifstream file{sequenceFile};

    string letter;
    while (file >> letter) {
        sequence.push_back(letter[0]); // Take the first index of each string to get the character
    }

    if (providedBlock) { // a nextBlock was provided
        index--; // Set index to -1 so the next iteration sets it to 0
        this->nextBlock = nextBlock;

    } else { // take from sequence
        this->nextBlock = sequence[0];
    }
}

Block * Level0::generateBlock() {

    Block * newBlock = createSpecificBlock(nextBlock);

    index++;
    if (index >= sequence.size()) {
        index = 0;
    }
    nextBlock = sequence[index];

    return newBlock;
}

Block * Level0::createSpecificBlock(char blockChar) {
    if (blockChar == 'I') {
        return new IBlock(0);
    } else if (blockChar == 'J') {
        return new JBlock(0);
    } else if (blockChar == 'L') {
        return new LBlock(0);
    } else if (blockChar == 'O') {
        return new OBlock(0);
    } else if (blockChar == 'S') {
        return new SBlock(0);
    } else if (blockChar == 'T') {
        return new TBlock(0);
    } else if (blockChar == 'Z') {
        return new ZBlock(0);
    } else {
        return nullptr;
    }
}
