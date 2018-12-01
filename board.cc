#include <cmath>
#include <string>

#include "board.h"

using namespace std;

const int width = 11;
const int height = 18;

Board::Board() : currBlock{nullptr},nextBlock{nullptr}, level{0}, lastClear{0}, blind{false}, heavy{false} {
    init();
}

void Board::init(){
    for(int i = 0; i < height; ++i){
        vector<Cell *> vec;
        for(int j = 0; j < width; ++j){
            Cell * newCell = new Cell(i,j);
            vec.push_back(newCell);
        }
        theGrid.push_back(vec);
    }
}

void Board::clearBoard(){
    for(int i = 0; i < height; ++i){
        for(int j = 0; j < width; ++j){
            delete theGrid[i][j];   //Delete the cell pointers in the grid
        }
    }
    theGrid.clear();
    delete currBlock;   //Delete the currBlock pointer in the grid
    currBlock = nullptr;
    delete nextBlock;
    nextBlock = nullptr;

    init();
}

bool Board::isRowFull(int row){
    for(int j = 0; j < width; ++j){
        if (!theGrid[row][j]->isFilled()){
            return false;
        }
    }
    return true;
}

void Board::clearRow(int row){
    for(int j = 0; j < width; ++j){
        theGrid[row][j]->setLetter("");
    }
}

bool Board::isAlive(){
    for(int i = 0; i < width; ++i){
        if(theGrid[i][2]->isFilled()){
            return false;   //Checks if any of the blocks in the 3 reserve rows are filled
        }
    }
    return true;
}

int Board::dropBlock(bool & multipleLines){    // Called from AbstractGame
    int numLines = 0;
    int scoredPoints = 0;
    currBlock->drop();
    blockList.push_back(currBlock);
    
    int blockRow = currBlock->getBottomLeft()->getRow();
    while(isRowFull(blockRow)){
        numLines += 1;  //Increment number of lines
        copyRow(blockRow - 1, blockRow);
        scoredPoints += updateBlockList();
        for(int i = blockRow - 1; i > 2; --i){
            copyRow(i - 1, i);
        }
    }
    
    //Make sure the dropped currBlock doesn't get deleted
    currBlock = nullptr;

    // reset special actions
    blind = false;
    heavy = false;

    if (numLines > 0){
        if (level == 4) {
            lastClear = 0;
        }
        if (numLines > 1) {
            multipleLines = true; // update multipleLines for AbstractGame to know for special action
        }
        scoredPoints += pow(numLines + level, 2);
        return scoredPoints;
    }else{
        if (level == 4) {
            lastClear++;
        }
        return 0;
    }

}

Board::~Board(){
    this->clearBoard();
}

string Board::getLine(int row){
    string res = "";
    for(int j = 0; j < width; ++j){
        if (blind && row >= 2 && row <= 11 && j >= 2 && j <= 8) {
          res += "?";
        } else if (theGrid[row][j]->isFilled()) {
            res += theGrid[row][j]->getLetter();
        } else {
            res += ".";
        }
    }
    return res;
}

Block * Board::getCurrentBlock(){
    return currBlock;
}

Block * Board::getNextBlock() {
   return nextBlock;
}

void Board::copyRow(int firstRow,int secondRow){
    for(int j = 0; j < width;++j){
        //Copies data of first row into second row
        theGrid[secondRow][j]->copyData(theGrid[firstRow][j]);
    }
    clearRow(firstRow);
}

int Board::updateBlockList(){
    int scoredPoints = 0;
    for(int i = 0; i < blockList.size();++i ) {
        int blockScore = blockList[i]->updateBlock();
        if(blockScore > 0){
            blockList.erase(blockList.begin()+i);
            i -= 1;
        }
        scoredPoints += blockScore;
    }
    return scoredPoints;
}

void Board::setLevel(int newLevel){
    level = newLevel;
    lastClear = 0;
}


void Board::createBlock(Block * newBlock){
    if (!nextBlock) { // The very first time, nextBlock is not initialized, so set it
        nextBlock = newBlock;
        return;
    }

    currBlock = nextBlock;
    nextBlock = newBlock;
    currBlock->init(theGrid[3][0], theGrid);
}

void Board::replaceBlock(Block * newBlock) {
    if (currBlock) {
        //Used when we want to replace the current undropped currBlock
        delete currBlock;
    }

    currBlock = newBlock;
    if (currBlock->getType() == "*") { // if level 4 block
        currBlock->init(theGrid[3][5], theGrid);
    } else {
        currBlock->init(theGrid[3][0], theGrid);
    }
}

void Board::setBlind() {
    blind = true;
}

void Board::setHeavy() {
    heavy = true;
}

int Board::getHeavyInt() {
    return heavy ? 2 : 0;
}

bool Board::shouldDropStar() {
    // drop a block if level 4 and last clear was a multiple of 5
    return (level == 4) && (lastClear % 5 == 0);
}
