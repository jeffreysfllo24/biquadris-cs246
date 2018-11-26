#include "board.h"
#include <string>
#include <cmath>
using namespace std;

const int width = 11;
const int height = 18;
Board::Board() : block{nullptr},level(0){
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
    delete block;   //Delete the block pointer in the grid
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

int Board::dropBlock(){    //Called from abstract game
    int numLines = 0;
    int scoredPoints = 0;
    block->drop();
    blockList.push_back(block);
    
    int blockRow = block->getBottomLeft()->getRow();
    while(isRowFull(blockRow)){
        numLines += 1;  //Increment number of lines
        copyRow(blockRow - 1, blockRow);
        scoredPoints += updateBlockList();
        for(int i = blockRow - 1; i > 2; --i){
            copyRow(i - 1, i);
        }
    }
    
    //Make sure the dropped block doesn't get deleted
    block = nullptr;
    
    if (numLines > 0){
        scoredPoints += pow(numLines + level,2);
        return scoredPoints;
    }else{
        return 0;
    }
}

Board::~Board(){
    this->clearBoard();
}

string Board::getLine(int row){
    string res = "";
    for(int j = 0; j < width; ++j){
        if(theGrid[row][j]->isFilled()){
            res += theGrid[row][j]->getLetter();
        }else{
            res += "."; // TODO change back to spaces
        }
    }
    return res;
}

Block * Board::getCurrentBlock(){
    return block;
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
    for ( auto &i : blockList ) {
        scoredPoints += i->updateBlock();
    }
    return scoredPoints;
}

void Board::createBlock(Block * other){
    if(block){
        //Used when we want to replace the current undropped block
        delete block;
    }
    block = other;
    block->init(theGrid[3][0], theGrid);
}


