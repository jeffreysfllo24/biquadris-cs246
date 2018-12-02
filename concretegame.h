#ifndef CONCRETEGAME_H
#define CONCRETEGAME_H

#include "abstractgame.h"
#include "score.h"

// Forward Declarations
class Level;

class ConcreteGame : public AbstractGame {
public:
    ConcreteGame(bool,std::string,std::string);
    void createBlock() override;
    void replaceSpecificBlock(char) override;
};

#endif //CONCRETEGAME_H
