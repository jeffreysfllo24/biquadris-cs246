#ifndef LEVEL0_H
#define LEVEL0_H

#include <string>
#include <vector>

#include "level.h"

class Level0 : public Level {
    int index;
    std::vector<char> sequence;
public:
    Level0(bool,std::string,std::string);
    Block * generateBlock() override;
    void setSeed(int) override;
};

#endif //LEVEL0_H
