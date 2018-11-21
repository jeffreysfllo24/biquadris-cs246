#ifndef LEVEL0_H
#define LEVEL0_H

#include "level.h"

class Level0 : public Level {
public:
    Block * generateBlock() override;
};

#endif //LEVEL0_H
