#include <cstdlib>
#include <fstream>
#include <string>

#include "level0.h"

using namespace std;

Level0::Level0(bool isPlayerOne): // Add each letter from input file to a vector
    index{0} {
    string sequenceFile = isPlayerOne ? "sequence1.txt" : "sequence2.txt"; // set sequence based on player
    ifstream file{sequenceFile};

    char letter;
    while (file >> letter) {
        sequence.push_back(letter);
    }


}

Block * Level0::generateBlock() {

    Block * newBlock = createSpecificBlock(sequence[index], 0);

    index++; // increase index, reset to zero if past end of vector
    if (index >= sequence.size()) {
        index = 0;
    }

    return newBlock;
}
