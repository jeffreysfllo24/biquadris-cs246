#ifndef LEVEL_H
#define LEVEL_H

#include <string>

// Forward Declaration
class Block;

class Level {
protected:
public:
    Block * createSpecificBlock(char, int);
    virtual Block * generateBlock() = 0;
    virtual void norandom(std::string);
    virtual void random();
    virtual ~Level() = 0;
    virtual void setSeed(int) = 0;
};

#endif //LEVEL_H
