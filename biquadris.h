#ifndef BIQUADRIS_H
#define BIQUADRIS_H

#include "interpreter.h"

// Forward Declarations
class AbstractGame;
class DisplayObserver;


class Biquadris {
    AbstractGame * playerOne;
    AbstractGame * playerTwo;
    DisplayObserver * textDisplay;
    Interpreter interpreter;

    void updateDisplay();
public:
    Biquadris();
    void run();
};

#endif //BIQUADRIS_H
