#include "board.h"
#include <string>
using namespace std;

const int width = 11;
const int height = 18;
Board::Board() : block{nullptr}{
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
        if (theGrid[row][j]->isFilled()){
            return false;
        }
    }
    return true;
}

//Delete if not used
void Board::clearRow(int row){
    for(int j = 0; j < width; ++j){
        delete theGrid[row][j];
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

void Board::dropBlock(Block *block){
    block->drop();
   /* int blockRow = block->getCell()->x
    while(isRowFull(blockRow)){
        for(int i = blockRow; i > 2; --i){
            copyRow(i - 1, i);
            //TODO: make more efficient check if row is empty
        }
    }
    */
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
            res += " ";
        }
    }
    return res;
}

Block * Board::getCurrentBlock(){
    return block;
}

void Board::copyRow(int firstRow,int secondRow){
    for(int j = 0; j < width;++j){
        theGrid[secondRow][j]->copyData(theGrid[firstRow][j]);
    }
}

void Board::createBlock(Block * other){
    if(block){
        delete block;
    }
    block = other;
    //block->init; TODO Jayson 
}


