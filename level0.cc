#include <cstdlib>
#include <fstream>
#include <string>

#include "level0.h"

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
