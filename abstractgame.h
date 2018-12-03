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
    int seed;
    std::string sequence1;
    std::string sequence2;
    Level * level;
    Board board;
    Score score;
public:
    virtual void createBlock() = 0;
    virtual void replaceSpecificBlock(char) = 0;
    void levelUp();
    void levelDown();
    void restart();
    void norandom(std::string);
    void random();
    int dropBlock();
    Board & getBoard();
    Score & getScore();
    int getLevel();
    void setLevel(int);
    void setSequences(std::string,std::string);
    void setSeed(int);
    virtual ~AbstractGame() = 0;
};

#endif // ABSTRACTGAME_H
