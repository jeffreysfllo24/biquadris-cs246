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
        SBlock(int levelVal = 0);
        void init(Cell *, std::vector<std::vector<Cell *>>) override;
        std::string getType() const override;
        Cell * getBottomLeft() const override;
        std::vector<Cell *> getBlockCells() const override;
        void clockwise(int dropAmount = 0) override;
        void counterclockwise(int dropAmount = 0) override;
        void left(int dropAmount = 0) override;
        void right(int dropAmount = 0) override;
        bool down(int dropAmount = 1) override;
        void drop() override;
        bool didLose() override;
        ~SBlock() override;
};

#endif
