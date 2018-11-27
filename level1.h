#ifndef LEVEL1_H
#define LEVEL1_H

#include "level.h"

class Level1 : public Level {
    char generateRandom();
public:
    Block * createSpecificBlock(char) override;
    Level1(char = ' ', bool = false);
    Block * generateBlock() override;
};

#endif //LEVEL1_H
