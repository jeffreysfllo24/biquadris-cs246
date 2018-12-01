#ifndef board_hpp
#define board_hpp

#include <iostream>
#include "block.h"
#include "cell.h"
#include <string>

class Board{
    Block * currBlock;
    Block * nextBlock;
    std::vector<std::vector<Cell *>> theGrid;
    int level;
    int lastClear; // used for level 4
    std::vector<Block *> blockList;
    bool blind; // used for blind special action
    bool heavy; // used for heavy special action
    public:
        Board();
        int updateBlockList(); //Checks if any blocks have been fully deleted
        void clearBoard();
        bool isRowFull(int);
        void clearRow(int);
        bool isAlive();
        int dropBlock(bool &);    //Abstract game calls board->drop and returns the score if any rows cleared
        Block * getCurrentBlock();
        Block * getNextBlock();
        std::string getLine(int);
        void copyRow(int firstRow,int secondRow);  //Copy contents of firstRow into secondRow
        ~Board();
        void init();
        void setLevel(int); //Setter for integer 
        void createBlock(Block *);
        void replaceBlock(Block *);
        void setBlind();
        void setHeavy();
        int getHeavyInt();
        bool shouldDropStar();
};

#endif /* board_hpp */
