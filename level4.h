#ifndef LEVEL4_H
#define LEVEL4_H

#include <vector>

#include "level.h"

class Level4 : public Level {
    bool useSequence;
    int index;
    std::vector<char> sequence;
    int seed;
    char generateRandom();
public:
    Level4();
    Block * generateBlock() override;
    void norandom(std::string) override;
    void random() override;
    void setSeed(int)override;
};


#endif //LEVEL4_H
