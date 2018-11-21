#include "board.h"
#include <string>
using namespace std;

const int width = 11;
const int height = 18;
const int startBoard = 3;
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

bool Board::isRowFull(Cell ** row){
    for(int i = 0; i < width; ++i){
        if (!row[i]->isFilled()){
            return false;
        }
    }
    return true;
}

void Board::clearRow(Cell ** row){
    for(int i = 0; i < width; ++i){
        delete row[i];
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

string getLine(Cell ** row){
    string res = "";
    for(int i = 0; i < width; ++i){
        if(row[i]->isFilled()){
            res += row[i]->getLetter();
        }else{
            res += " ";
        }
    }
    return res;
}
