#ifndef tblock_hpp
#define tblock_hpp

#include "block.h"

class TBlock : public Block {
    std::vector<std::vector<Cell *>> blockGrid;
    // rotation
    std::vector<Cell *> getPositionZero();
    std::vector<Cell *> getPositionOne();
    std::vector<Cell *> getPositionTwo();
    std::vector<Cell *> getPositionThree();
    bool isValidMove(std::vector<Cell *>) const override;
    bool replaceCells(std::vector<Cell *>, std::string) override;
    public:
        TBlock();
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
        ~TBlock() override;
};

#endif
