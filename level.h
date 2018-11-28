#ifndef LEVEL_H
#define LEVEL_H

#include <string>

// Forward Declaration
class Block;

class Level {
protected:
    char nextBlock;
public:
    Block * createSpecificBlock(char, int);
    virtual Block * generateBlock() = 0;
    virtual void norandom(std::string);
    virtual void random();
    char getNextBlock();
    virtual ~Level() = 0;
};

#endif //LEVEL_H
