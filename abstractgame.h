#ifndef ABSTRACTGAME_H
#define ABSTRACTGAME_H

#include <string>

#include "board.h"

// Forward Declaration
class Level;

class AbstractGame {
public:
    virtual void setOtherGame(AbstractGame *) = 0;
    virtual void createBlock() = 0;
    virtual void createSpecificBlock(char) = 0;
    virtual void restart() = 0;
    virtual Board & getBoard() = 0;
};

#endif // ABSTRACTGAME_H
