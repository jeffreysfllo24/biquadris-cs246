#ifndef sblock_hpp
#define sblock_hpp

#include "block.h"

class SBlock : public Block {
    std::vector<std::vector<Cell *>> blockGrid;
    // rotation
    std::vector<Cell *> getPositionZero();
    std::vector<Cell *> getPositionOne();
    bool isValidMove(std::vector<Cell *>) const override;
    bool replaceCells(std::vector<Cell *>, std::string) override;
    public:
        SBlock();
        void init(Cell *, std::vector<std::vector<Cell *>>) override;
        std::string getType() const override;
        Cell * getBottomLeft() const override;
        std::vector<Cell *> getBlockCells() const override;
        void clockwise() override;
        void counterclockwise() override;
        void left() override;
        void right() override;
        bool down() override;
        void drop() override;
        bool didLose() override;
        ~SBlock() override;
};

#endif
