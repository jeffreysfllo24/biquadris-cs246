#ifndef LEVEL1_H
#define LEVEL1_H

#include "level.h"

class Level1 : public Level {
    char generateRandom();
public:
    Level1();
    Block * generateBlock() override;
};

#endif //LEVEL1_H
