#ifndef LEVEL3_H
#define LEVEL3_H

#include <string>
#include <vector>

#include "level.h"

class Level3 : public Level {
    bool useSequence;
    int index;
    std::vector<char> sequence;

    char generateRandom();
public:
    Level3(char = ' ', bool = false);
    Block * generateBlock() override;
    void norandom(std::string) override;
    void random() override;
};

#endif //LEVEL3_H
