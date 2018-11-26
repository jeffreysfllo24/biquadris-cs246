#include "block.h"
#include <cmath>
using namespace std;

Block::~Block() {}

int Block::updateBlock(){
    int score = 0;
    int count = 0;
    for( auto &cell : blockCells){
        if(!cell->isFilled()){  //Remove cell from block if it is deleted
            blockCells.erase(blockCells.begin() + count);
        }else{
            count += 1;
        }
    }
    if(blockCells.empty()){
        score += pow(level + 1,2);
    }
    return score;
}
