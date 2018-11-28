#include "biquadris.h"
#include "concretegame.h"
#include "textdisplay.h"

using namespace std;

Biquadris::Biquadris():
    isPlayerOnePlaying{true}, isGameOver{false},
    playerOne{new ConcreteGame{true}}, playerTwo{new ConcreteGame{false}},
    textDisplay{new TextDisplay{this}}, interpreter{Interpreter{this}} {

    playerOne->setOtherGame(playerTwo); // Give players access to other player
    playerTwo->setOtherGame(playerOne); // for special actions
}

void Biquadris::updateDisplay() {
    textDisplay->displayBoard();
}

void Biquadris::startGame() {
    playerOne->createBlock();
    playerOne->createBlock();
    playerTwo->createBlock();
    playerTwo->createBlock();
}

void Biquadris::run() {
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

AbstractGame * Biquadris::getFirstPlayer(){
    return playerOne;
}

AbstractGame * Biquadris::getSecondPlayer(){
    return playerTwo;
}
