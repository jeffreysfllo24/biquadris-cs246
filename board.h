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
        bool isRowFull(Cell **);
        void clearRow(Cell **);
        bool isAlive();
        void setBlock(Block *);    //Game calls board->setBlock(block)
        std::string getLine(Cell **);
        ~Board();
        void init();
};

#endif /* board_hpp */
