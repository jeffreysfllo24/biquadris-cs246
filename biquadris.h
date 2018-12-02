#ifndef BIQUADRIS_H
#define BIQUADRIS_H

#include "interpreter.h"
#include <string>
// Forward Declarations
class AbstractGame;
class DisplayObserver;


class Biquadris {
    bool isPlayerOnePlaying;
    bool isGameOver;
    AbstractGame * playerOne;
    AbstractGame * playerTwo;
    DisplayObserver * textDisplay;
    DisplayObserver * graphicsDisplay;
    Interpreter interpreter;
    bool multipleSpecialActions;
    void updateDisplay();
    void startGame();
public:
    Biquadris(std::string,std::string);
    void run(bool isText,int seed, std::string sequence1, std::string sequence2,int startlevel);
    void switchPlayers();
    void restart();
    bool getIsGameOver();
    AbstractGame * getCurrentPlayer();
    AbstractGame * getNonCurrentPlayer();
    AbstractGame *getFirstPlayer();
    AbstractGame *getSecondPlayer();
    void toggleMultipleSpecialActions();
    bool getMultipleSpecialActions();
};

#endif //BIQUADRIS_H
