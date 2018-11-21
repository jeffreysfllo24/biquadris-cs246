#ifndef iblock_hpp
#define iblock_hpp

#include "block.h"

class IBlock : public Block {
    int rotation;
    Cell * bottomLeft;
    Cell *** blockGrid;
    std::vector<Cell *> blockCells;
    public:
        IBlock(Cell *, Cell ***);
        char getBlockType() const override;
        bool isValidMove(std::vector<Cell *>) const override;
        void clockwise() override;
        void counterclockwise() override;
        void left() override;
        void right() override;
        void down() override;
        void drop() override;
        ~IBlock() override;
};

#endif