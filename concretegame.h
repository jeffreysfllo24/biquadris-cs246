#ifndef CONCRETEGAME_H
#define CONCRETEGAME_H

#include "abstractgame.h"
#include "score.h"

// Forward Declarations
class Level;

class ConcreteGame : public AbstractGame {
    int levelInt;
    Level * level;
    AbstractGame * otherGame;
    Board board;
    Score score;
public:
    ConcreteGame();
    void setOtherGame(AbstractGame *) override;
    void createBlock() override;
    void createSpecificBlock(char) override;
};

#endif //CONCRETEGAME_H
