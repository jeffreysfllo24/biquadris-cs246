#ifndef block_hpp
#define block_hpp

#include <iostream>
#include <vector>
#include "cell.h"

class Block {
    int rotation; // ranges from 0 to 3
    int maxWidth; // width of the block
    bool isBottom;
    Cell * bottomLeft; // pointer to the bottom left cell
    std::vector<Cell *> blockCells; // vector of all cells inside block
    public:
        virtual char prettyPrint() const = 0;
        virtual bool isValidMove(std::vector<Cell *>) const = 0;
        virtual void replaceCells(std::vector<Cell *> tempCells) = 0;
        virtual void clockwise() = 0;
        virtual void counterclockwise() = 0;
        virtual void left() = 0;
        virtual void right() = 0;
        virtual void down() = 0;
        virtual void drop() = 0;
        virtual ~Block();
};

#endif /* block_hpp */
