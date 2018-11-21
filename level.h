#ifndef LEVEL_H
#define LEVEL_H

// Forward Declaration
class Block;

class Level {
public:
    virtual Block * generateBlock() = 0;
};

#endif //LEVEL_H
