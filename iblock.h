#ifndef iblock_hpp
#define iblock_hpp

#include "block.h"

class IBlock : public Block {
    Cell * bottomLeft;
    std::vector<Cell *> blockCells;
    std::vector<std::vector<Cell *>> blockGrid;

    //movement
    bool isBottom;
    bool isValidMove(std::vector<Cell *>) const override;
    bool replaceCells(std::vector<Cell *>, std::string letter) override;

    // rotation
    int rotation;
    int maxWidth;
    std::vector<Cell *> getPositionZero();
    std::vector<Cell *> getPositionOne();
    
    public:
        IBlock();
        void init(Cell *, std::vector<std::vector<Cell *>>) override;
        std::string getType() const override;
        Cell * getBottomLeft() const override;
        void clockwise() override;
        void counterclockwise() override;
        void left() override;
        void right() override;
        bool down() override;
        void drop() override;
        ~IBlock() override;
};

#endif
