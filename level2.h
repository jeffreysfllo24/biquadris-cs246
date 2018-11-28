#ifndef LEVEL2_H
#define LEVEL2_H

#include "level.h"

class Level2 : public Level {
    char generateRandom();
public:
    Block * createSpecificBlock(char) override;
    Level2(char = ' ', bool = false);
    Block * generateBlock() override;
};

#endif //LEVEL2_H
