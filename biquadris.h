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
    void updateDisplay(bool);
    bool multipleSpecialActions;
    void startGame();
public:
    Biquadris(std::string,std::string,bool);
    void run(bool isGraphics,int seed, std::string sequence1, std::string sequence2,int startlevel);
    void switchPlayers();
    void restart();
    bool getIsGameOver();
    void displayHelp();
    AbstractGame * getCurrentPlayer();
    AbstractGame * getNonCurrentPlayer();
    ~Biquadris();
    AbstractGame *getFirstPlayer();
    AbstractGame *getSecondPlayer();
    void toggleMultipleSpecialActions();
    bool getMultipleSpecialActions();
};

#endif //BIQUADRIS_H
