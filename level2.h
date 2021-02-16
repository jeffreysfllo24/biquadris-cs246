#ifndef LEVEL2_H
#define LEVEL2_H

#include "level.h"

class Level2 : public Level {
    char generateRandom();
    int seed;
public:
    Level2();
    Block * generateBlock() override;
    void setSeed(int)override;
};

#endif //LEVEL2_H
