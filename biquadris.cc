#include "biquadris.h"
#include "concretegame.h"
#include "textdisplay.h"
#include "graphicsdisplay.h"

using namespace std;

Biquadris::Biquadris(string sequence1,string sequence2):
    isPlayerOnePlaying{true}, isGameOver{false},
    playerOne{new ConcreteGame{true,sequence1,sequence2}}, playerTwo{new ConcreteGame{false,sequence1,sequence2}},
    textDisplay{new TextDisplay{this}}, graphicsDisplay{new GraphicsDisplay{this}}, interpreter{Interpreter{this}} {

    playerOne->setOtherGame(playerTwo); // Give players access to other player
    playerTwo->setOtherGame(playerOne); // for special actions
}

void Biquadris::updateDisplay() {
    textDisplay->displayBoard();
    graphicsDisplay->displayBoard();
}

void Biquadris::startGame() {
    playerOne->createBlock();
    playerOne->createBlock();
    playerTwo->createBlock();
    playerTwo->createBlock();
}

void Biquadris::run(bool isText,int seed, string sequence1, string sequence2,int startlevel) {
    //Set sequence1 and sequence2 files for Level0 to read
    playerOne->setSequences(sequence1, sequence2);
    playerTwo->setSequences(sequence1, sequence2);
    
    //Set start level
    playerOne->setLevel(startlevel);
    playerTwo->setLevel(startlevel);
    
    //Set seed
    playerOne->setSeed(seed);
    playerTwo->setSeed(seed);
    
    //TODO:Logic to allow only test display when graphics display is implemented
    
    startGame();
    updateDisplay();
    
    string command;
    while (cin >> command) {
        interpreter.interpretCommand(command);
        updateDisplay();
    }
}

void Biquadris::switchPlayers() {
    try {
        getCurrentPlayer()->createBlock(); // Create new currBlock for current player as other player already has a currBlock
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
