#ifndef LEVEL3_H
#define LEVEL3_H

#include "level.h"

class Level3 : public Level {
    char generateRandom();
public:
    Block * createSpecificBlock(char) override;
    Level3(char = ' ', bool = false);
    Block * generateBlock() override;
};

#endif //LEVEL3_H
