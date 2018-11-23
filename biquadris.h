#ifndef BIQUADRIS_H
#define BIQUADRIS_H

#include "interpreter.h"

// Forward Declarations
class AbstractGame;
class DisplayObserver;


class Biquadris {
    bool isPlayerOnePlaying;
    AbstractGame * playerOne;
    AbstractGame * playerTwo;
    DisplayObserver * textDisplay;
    Interpreter interpreter;
    void updateDisplay();
public:
    Biquadris();
    void run();
    AbstractGame * getCurrentPlayer();
    AbstractGame *getFirstPlayer();
    AbstractGame *getSecondPlayer();
};

#endif //BIQUADRIS_H
