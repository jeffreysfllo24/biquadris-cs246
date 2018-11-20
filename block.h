#ifndef block_hpp
#define block_hpp

#include <iostream>
#include "coordinate.h"

class Block {
    int livesCounter;
    Coordinate coord;
    public:
        virtual void clockwise() = 0;
        virtual void counterclockwise() = 0;
        virtual void left() = 0;
        virtual void right() = 0;
        virtual void down() = 0;
        virtual void drop() = 0;
        virtual ~Block();
};

#endif /* block_hpp */
