#include <cstdlib>

#include <string>
#include <fstream>

#include "level0.h"
#include "iblock.h"
#include "oblock.h"
#include "tblock.h"

using namespace std;

Level0::Level0(string & filename): // Add each letter from input file to a vector
    index{0} {
    ifstream file{filename};

    string letter;
    while (file >> letter) {
        sequence.push_back(letter[0]); // Take the first index of each string to get the character
    }
}

Block * Level0::generateBlock() {
     return new IBlock;

    /*
    Block * newBlock;
    if (sequence[index] == 'I') {
        newBlock = new IBlock;
    } else if (sequence[index] == 'J') {
        newBlock = new JBlock;
    } else if (sequence[index] == 'L') {
        newBlock = new LBlock;
    } else if (sequence[index] == 'O') {
        newBlock = new OBlock;
    } else if (sequence[index] == 'S') {
        newBlock = new SBlock;
    } else if (sequence[index] == 'T') {
        newBlock = new TBlock;
    } else  {// if (sequence[index] == 'Z')
        newBlock = new ZBlock;
    }

    index++;
    if (index >= sequence.length()) {
        index = 0;
    }
     */
}

char Level0::nextBlock() {
    return sequence[index];
//    return 'O';
}
