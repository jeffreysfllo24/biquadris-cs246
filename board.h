#ifndef board_hpp
#define board_hpp

#include <iostream>
#include "block.h"
#include "cell.h"
#include <string>

class Board{
    Block *block;
    Cell *** theGrid;
    public:
        Board();
        void clearBoard();
        bool isRowFull(int);
        void clearRow(int);
        bool isAlive();
        void setBlock(Block *);    //Game calls board->setBlock(block)
        Block * getCurrentBlock();
        std::string getLine(int);
        void copyRow(int firstRow,int secondRow);  //Copy contents of firstRow into secondRow
        ~Board();
        void init();
};

#endif /* board_hpp */
