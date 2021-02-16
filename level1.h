#ifndef LEVEL1_H
#define LEVEL1_H

#include "level.h"

class Level1 : public Level {
    char generateRandom();
    int seed;
public:
    Level1();
    Block * generateBlock() override;
    void setSeed(int) override;
};

#endif //LEVEL1_H
