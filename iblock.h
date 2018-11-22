#ifndef iblock_hpp
#define iblock_hpp

#include "block.h"

class IBlock : public Block {
    Cell * bottomLeft;
    std::vector<Cell *> blockCells;
    Cell *** blockGrid;

    //movement
    bool isBottom;
    bool isValidMove(std::vector<Cell *>) const override;
    void replaceCells(std::vector<Cell *>) override;

    // rotation
    int rotation;
    int maxWidth;
    std::vector<Cell *> getPositionZero();
    std::vector<Cell *> getPositionOne();
    
    public:
        IBlock(Cell *, Cell ***);
        std::string getType() const override;
        void clockwise() override;
        void counterclockwise() override;
        void left() override;
        void right() override;
        void down() override;
        void drop() override;
        ~IBlock() override;
};

#endif