#ifndef LEVEL4_H
#define LEVEL4_H

#include "level.h"

class Level4 : public Level {
    char generateRandom();
public:
    Block * createSpecificBlock(char) override;
    Level4(char = ' ', bool = false);
    Block * generateBlock() override;
};


#endif //LEVEL4_H
