#ifndef ABSTRACTGAME_H
#define ABSTRACTGAME_H

#include <string>

class AbstractGame {
    int level;
    AbstractGame * otherGame;
    // Board board;
    // Score score;
public:
    void setOtherGame(AbstractGame *);
    virtual void takeTurn() = 0;
    virtual void restart() = 0;
};

#endif // ABSTRACTGAME_H
