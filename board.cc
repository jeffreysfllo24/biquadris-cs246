#include "board.h"
#include <string>
using namespace std;

const int width = 11;
const int height = 18;
Board::Board() : block{nullptr}, theGrid{} {
}

void Board::init(){
    for(int i = 0; i < height; ++i){
        for(int j = 0; j < width; ++j){
            Cell * newCell = new Cell(i,j);
            theGrid[i][j] = newCell;
        }
    }
}

void Board::clearBoard(){
    for(int i = 0; i < height; ++i){
        for(int j = 0; j < width; ++j){
            delete theGrid[i][j];   //Delete the cell pointers in the grid
        }
    }
    delete theGrid; //Delete the grid itself
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

void Board::setBlock(Block *block){
    
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

