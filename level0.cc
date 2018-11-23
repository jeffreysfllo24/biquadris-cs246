#include <cstdlib>

#include <string>
#include <fstream>

#include "level0.h"
#include "iblock.h"

using namespace std;

Level0::Level0(string filename): // Add each letter from input file to a vector
    index{0} {
    ifstream file{filename};
    string letter;
    while (file >> letter) {
        sequence.push_back(letter[0]); // Take the first index of each string to get the character
    }
}

Block * Level0::generateBlock() {
    // return new IBlock;

    /*if (sequence[index] == 'I') {
        return new IBlock;
    } else if (sequence[index] == 'J') {
        return new JBlock;
    } else if (sequence[index] == 'L') {
        return new LBlock;
    } else if (sequence[index] == 'O') {
        return new OBlock;
    } else if (sequence[index] == 'S') {
        return new SBlock;
    } else if (sequence[index] == 'T') {
        return new TBlock;
    } else  {// if (sequence[index] == 'Z')
        return new ZBlock;
    }*/

}
