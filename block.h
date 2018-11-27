#ifndef block_hpp
#define block_hpp

#include <iostream>
#include <vector>
#include "cell.h"

class Block {
    protected:
        Cell * bottomLeft; // pointer to the bottom left cell
        std::vector<Cell *> blockCells; // vector of all cells inside block
        int level; //The Level that the block was generated in
        // movement
        bool isBottom;
        virtual bool isValidMove(std::vector<Cell *>) const = 0;
        virtual bool replaceCells(std::vector<Cell *>, std::string) = 0;

        // rotation
        int rotation;
        int maxWidth; // width of the next rotation
    
    public:
        virtual void init(Cell *, std::vector<std::vector<Cell *>>) = 0;
        virtual std::string getType() const = 0;
        virtual Cell * getBottomLeft() const = 0;
        virtual std::vector<Cell *> getBlockCells() const = 0;
        virtual void clockwise(int dropAmount = 0) = 0;
        virtual void counterclockwise(int dropAmount = 0) = 0;
        virtual void left(int dropAmount = 0) = 0;
        virtual void right(int dropAmount = 0) = 0;
        virtual bool down(int dropAmount = 1) = 0;
        virtual void drop() = 0;
        virtual bool didLose() = 0;
        int updateBlock();
        virtual ~Block();
    
};

#endif /* block_hpp */
