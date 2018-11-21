#ifndef ABSTRACTGAME_H
#define ABSTRACTGAME_H

#include <string>

#include "board.h"

// Forward Declaration
class Level;

class AbstractGame {
    int levelInt;
    Level * level;
    AbstractGame * otherGame;
    Board board;
    // Score score;
public:
    void setOtherGame(AbstractGame *);
    virtual void restart() = 0;
    Board & getBoard();
};

#endif // ABSTRACTGAME_H
