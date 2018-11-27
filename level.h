#ifndef LEVEL_H
#define LEVEL_H

// Forward Declaration
class Block;

class Level {
protected:
    char nextBlock;
public:
    virtual Block * generateBlock() = 0;
    Block * createSpecificBlock(char);
    char getNextBlock();
    virtual ~Level() = 0;
};

#endif //LEVEL_H
