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
    virtual void createSpecificBlock(char) = 0; // TODO not used?
    virtual void replaceSpecificBlock(char) = 0;
    void levelUp();
    void levelDown();
    void restart();
    void norandom(std::string);
    void random();
    bool dropBlock();
    Board & getBoard();
    Score & getScore();
    int getLevel();
    virtual ~AbstractGame() = 0;
};

#endif // ABSTRACTGAME_H
