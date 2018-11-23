#ifndef CONCRETEGAME_H
#define CONCRETEGAME_H

#include "abstractgame.h"
#include "score.h"

// Forward Declarations
class Level;

class ConcreteGame : public AbstractGame {
    bool isPlayerOne;
    int levelInt;
    Level * level;
    AbstractGame * otherGame;
    Board board;
    Score score;
public:
    ConcreteGame(bool);
    void setOtherGame(AbstractGame *) override;
    void createBlock() override;
    void createSpecificBlock(char) override;
    void restart() override;
    Board & getBoard() override;
};

#endif //CONCRETEGAME_H
