#ifndef board_hpp
#define board_hpp

#include <iostream>
#include "block.h"
#include "cell.h"
#include <string>

class Board{
    Block *block;
    std::vector<std::vector<Cell *>> theGrid;
    public:
        Board();
        void clearBoard();
        bool isRowFull(int);
        void clearRow(int);
        bool isAlive();
        void dropBlock();    //Game calls board->dropBlock() to PLACE block
        Block * getCurrentBlock();
        std::string getLine(int);
        void copyRow(int firstRow,int secondRow);  //Copy contents of firstRow into secondRow
        ~Board();
        void init();
        void createBlock(Block *);
};

#endif /* board_hpp */
