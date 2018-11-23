#ifndef ABSTRACTGAME_H
#define ABSTRACTGAME_H

#include <string>

#include "board.h"
#include "score.h"

// Forward Declaration
class Level;

class AbstractGame {
    int levelInt;
    Level * level;
    AbstractGame * otherGame;
    Board board;
    Score score;
public:
    void restart();
    Board & getBoard();
    virtual void setOtherGame(AbstractGame *) = 0;
    virtual void createBlock() = 0;
    virtual void createSpecificBlock(char) = 0;
    virtual ~AbstractGame() = 0;
};

#endif // ABSTRACTGAME_H
