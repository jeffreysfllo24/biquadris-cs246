#ifndef board_hpp
#define board_hpp

#include <iostream>
#include "block.h"
#include "cell.h"

class Board {
    Block ** blocks;
    Cell ** theGrid;
    public:
        Board();
        void clearBoard();
        bool isRowFull();
        void clearRows();
        bool isAlive();
        void setBlock();
        ~Board();
};

#endif /* board_hpp */
