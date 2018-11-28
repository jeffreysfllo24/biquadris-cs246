#include <cstdlib>
#include <fstream>
#include <string>

#include "level3.h"

using namespace std;

char Level3::generateRandom() {
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

Level3::Level3(char nextBlock, bool providedBlock): useSequence{false} {
    if (providedBlock) {
        this->nextBlock = nextBlock;
    } else {
        this->nextBlock = generateRandom();
    }
}

Block * Level3::generateBlock() {
    Block * newBlock = createSpecificBlock(nextBlock, 3);

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

void Level3::norandom(string filename) {
    useSequence = true;

    ifstream file{filename};

    string letter;
    while (file >> letter) {
        sequence.push_back(letter[0]); // Take the first index of each string to get the character
    }
}

void Level3::random() {
    useSequence = false;
    index = 0;
    sequence.clear();
}
