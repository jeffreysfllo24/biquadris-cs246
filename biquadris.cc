#include "biquadris.h"
#include "concretegame.h"
#include "textdisplay.h"
#include "graphicsdisplay.h"

using namespace std;

Biquadris::Biquadris(string sequence1,string sequence2,bool isGraphics):
    isPlayerOnePlaying{true}, isGameOver{false},
    playerOne{new ConcreteGame{true,sequence1,sequence2}}, playerTwo{new ConcreteGame{false,sequence1,sequence2}},
    textDisplay{new TextDisplay{this}}, graphicsDisplay{new GraphicsDisplay{this}}, interpreter{Interpreter{this}},
    multipleSpecialActions{false} {
}

void Biquadris::displayHelp(){
    textDisplay->printHelp();
    graphicsDisplay->printHelp();
}

void Biquadris::updateDisplay(bool isGraphics) {
    textDisplay->displayBoard();
    if(isGraphics){
        graphicsDisplay->displayBoard();
    }
}

void Biquadris::startGame() {
    playerOne->createBlock();
    playerOne->createBlock();
    playerTwo->createBlock();
    playerTwo->createBlock();
}

void Biquadris::run(bool isGraphics,int seed, string sequence1, string sequence2,int startlevel) {
    //Set sequence1 and sequence2 files for Level0 to read being done in constructor
    
    //Set start level
    playerOne->setLevel(startlevel);
    playerTwo->setLevel(startlevel);
    
    //Set seed
    playerOne->setSeed(seed);
    playerTwo->setSeed(seed);
    
    startGame();
    updateDisplay(isGraphics);
    
    string command;
    while (cin >> command) {
        interpreter.interpretCommand(command);
        if(command != "help"){
            updateDisplay(isGraphics);
        }
    }
}

void Biquadris::switchPlayers() {
    try {
        getCurrentPlayer()->createBlock(); // Create new currBlock for current player for next turn
        isPlayerOnePlaying = !isPlayerOnePlaying;
    } catch (runtime_error & err) {
        cerr << err.what() << endl;
        isGameOver = true;
    }
}

void Biquadris::restart() {
    playerOne->restart(); // reset boards
    playerTwo->restart();
    isPlayerOnePlaying = true; // player one begins

    startGame(); // create starting blocks

    isGameOver = false; // allow play again
}

bool Biquadris::getIsGameOver() {
    return isGameOver;
}

AbstractGame * Biquadris::getCurrentPlayer() {
    if (isPlayerOnePlaying) {
        return playerOne;
    } else {
        return playerTwo;
    }
}

AbstractGame * Biquadris::getNonCurrentPlayer() {
    if (isPlayerOnePlaying) {
        return playerTwo;
    } else {
        return playerOne;
    }
}

AbstractGame * Biquadris::getFirstPlayer(){
    return playerOne;
}

AbstractGame * Biquadris::getSecondPlayer(){
    return playerTwo;
}

Biquadris::~Biquadris() {
    delete playerOne;
    delete playerTwo;
    delete textDisplay;
    delete graphicsDisplay;
}

void Biquadris::toggleMultipleSpecialActions() {
    multipleSpecialActions = !multipleSpecialActions;
}
bool Biquadris::getMultipleSpecialActions() {
    return multipleSpecialActions;
}