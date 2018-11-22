#ifndef block_hpp
#define block_hpp

#include <iostream>
#include <vector>
#include "cell.h"

class Block {
    Cell * bottomLeft; // pointer to the bottom left cell
    std::vector<Cell *> blockCells; // vector of all cells inside block
    
    // movement
    bool isBottom;
    virtual bool isValidMove(std::vector<Cell *>) const = 0;
    virtual void replaceCells(std::vector<Cell *> tempCells) = 0;

    // rotation
    int rotation;
    int maxWidth; // width of the next rotation
    
    public:
        virtual std::string getType() const = 0;
        virtual void clockwise() = 0;
        virtual void counterclockwise() = 0;
        virtual void left() = 0;
        virtual void right() = 0;
        virtual void down() = 0;
        virtual void drop() = 0;
        virtual ~Block();
};

#endif /* block_hpp */
