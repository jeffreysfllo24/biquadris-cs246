#ifndef CONCRETEGAME_H
#define CONCRETEGAME_H

#include "abstractgame.h"

class ConcreteGame : public AbstractGame {
    int level;
    AbstractGame * otherGame;
    // Board board;
    // Score score;
public:
    ConcreteGame();
    void takeTurn() override;
    void restart() override;
};

#endif //CONCRETEGAME_H
