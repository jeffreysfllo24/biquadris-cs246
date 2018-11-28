#ifndef LEVEL2_H
#define LEVEL2_H

#include "level.h"

class Level2 : public Level {
    char generateRandom();
public:
    Level2();
    Block * generateBlock() override;
};

#endif //LEVEL2_H
