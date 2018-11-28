#ifndef LEVEL4_H
#define LEVEL4_H

#include <vector>

#include "level.h"

class Level4 : public Level {
    bool useSequence;
    int index;
    std::vector<char> sequence;

    char generateRandom();
public:
    Block * createSpecificBlock(char) override;
    Level4(char = ' ', bool = false);
    Block * generateBlock() override;
    void norandom(std::string) override;
    void random() override;
};


#endif //LEVEL4_H
