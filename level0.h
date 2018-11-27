#ifndef LEVEL0_H
#define LEVEL0_H

#include <string>
#include <vector>

#include "level.h"

class Level0 : public Level {
    int index;
    std::vector<char> sequence;
public:
    Block * createSpecificBlock(char) override;
    Level0(bool, char = ' ', bool = false);
    Block * generateBlock() override;
};

#endif //LEVEL0_H
