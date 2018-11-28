#ifndef BIQUADRIS_H
#define BIQUADRIS_H

#include "interpreter.h"

// Forward Declarations
class AbstractGame;
class DisplayObserver;


class Biquadris {
    bool isPlayerOnePlaying;
    bool isGameOver;
    AbstractGame * playerOne;
    AbstractGame * playerTwo;
    DisplayObserver * textDisplay;
    Interpreter interpreter;
    void updateDisplay();
    void startGame();
public:
    Biquadris();
    void run();
    void switchPlayers();
    void restart();
    bool getIsGameOver();
    AbstractGame * getCurrentPlayer();
    AbstractGame *getFirstPlayer();
    AbstractGame *getSecondPlayer();
};

#endif //BIQUADRIS_H
