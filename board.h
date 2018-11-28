#ifndef board_hpp
#define board_hpp

#include <iostream>
#include "block.h"
#include "cell.h"
#include <string>

class Board{
    Block *block;
    std::vector<std::vector<Cell *>> theGrid;
    int level;  //TODO: Change level integer based on command interpreter
    std::vector<Block *> blockList;
    public:
        Board();
        int updateBlockList(); //Checks if any blocks have been fully deleted
        void clearBoard();
        bool isRowFull(int);
        void clearRow(int);
        bool isAlive();
        int dropBlock();    //Abstract game calls board->drop and returns the score if any rows cleared
        Block * getCurrentBlock();
        std::string getLine(int);
        void copyRow(int firstRow,int secondRow);  //Copy contents of firstRow into secondRow
        ~Board();
        void init();
        void setLevel(int); //Setter for integer 
        void createBlock(Block *);
};

#endif /* board_hpp */
