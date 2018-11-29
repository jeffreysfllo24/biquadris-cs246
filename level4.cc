#include <cstdlib>
#include <fstream>
#include <string>

#include "level4.h"

using namespace std;

char Level4::generateRandom() {
    int r = rand() % 9;
    srand(seed);
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

Level4::Level4(): useSequence{false} {}

Block * Level4::generateBlock() {
    char nextBlockChar;

    if (useSequence) {
        nextBlockChar = sequence[index];

        index++;
        if (index >= sequence.size()) {
            index = 0;
        }
    } else {
        nextBlockChar = generateRandom();
    }

    Block * newBlock = createSpecificBlock(nextBlockChar, 3);

    return newBlock;
}

void Level4::norandom(string filename) {
    useSequence = true;

    ifstream file{filename};

    char letter;
    while (file >> letter) {
        sequence.push_back(letter);
    }
}

void Level4::random() {
    useSequence = false;
    index = 0;
    sequence.clear();
}

void Level4::setSeed(int newSeed){
    seed = newSeed;
}
