#ifndef LEVEL_H
#define LEVEL_H

#include <string>

// Forward Declaration
class Block;

class Level {
protected:
    char nextBlock;
public:
    virtual Block * generateBlock() = 0;
    Block * createSpecificBlock(char);
    char getNextBlock();
    virtual void norandom(std::string);
    virtual void random();
    virtual ~Level() = 0;
};

#endif //LEVEL_H
