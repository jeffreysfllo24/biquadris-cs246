#ifndef CONCRETEGAME_H
#define CONCRETEGAME_H

#include "abstractgame.h"

// Forward Declarations
class Level;

class ConcreteGame : public AbstractGame {
    int levelInt;
    Level * level;
    AbstractGame * otherGame;
    Board board;
    // Score score;
public:
    ConcreteGame();
    void takeTurn() override;
    void restart() override;
};

#endif //CONCRETEGAME_H
