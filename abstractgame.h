#ifndef ABSTRACTGAME_H
#define ABSTRACTGAME_H

#include <string>

#include "board.h"
#include "score.h"

// Forward Declaration
class Level;

class AbstractGame {
protected:
    bool isPlayerOne;
    int levelInt;
    Level * level;
    AbstractGame * otherGame;
    Board board;
    Score score;
public:
    virtual void setOtherGame(AbstractGame *) = 0;
    virtual void createBlock() = 0;
    virtual void createSpecificBlock(char) = 0;
    void restart();
    Board & getBoard();
    Score & getScore();
    char getNextBlock();
    int getLevel();
    virtual ~AbstractGame() = 0;
};

#endif // ABSTRACTGAME_H
