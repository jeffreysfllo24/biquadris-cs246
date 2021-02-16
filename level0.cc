#include <cstdlib>
#include <fstream>
#include <string>

#include "level0.h"

using namespace std;

Level0::Level0(bool isPlayerOne,string sequence1, string sequence2): // Add each letter from input file to a vector
    index{0} {
    string sequenceFile = isPlayerOne ? sequence1 : sequence2; // set sequence based on player
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

void Level0::setSeed(int newSeed){
    //Does nothing because not random
}
