#include "block.h"
#include <cmath>
using namespace std;

Block::~Block() {}

int Block::updateBlock(){
    int score = 0;
    for(int i = 0; i < blockCells.size();i++){
        //Remove cell from block if it is deleted
        if(!(blockCells[i]->isFilled())){
            blockCells.erase(blockCells.begin() + i);
            i -= 1;
        }
    }
    if(blockCells.size() == 0){
        score += pow(level + 1,2);
    }
    return score;
}

void Block::setLevel(int newLevel){
    level = newLevel;
}
