#ifndef BIQUADRIS_H
#define BIQUADRIS_H

// Forward Declarations
class AbstractGame;
class DisplayObserver;


class Biquadris {
    AbstractGame * playerOne;
    AbstractGame * playerTwo;
    DisplayObserver * textDisplay;
public:
    Biquadris();
    void updateDisplay();
};

#endif //BIQUADRIS_H
