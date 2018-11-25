#include "biquadris.h"
#include "concretegame.h"
#include "textdisplay.h"

using namespace std;

Biquadris::Biquadris():
    isPlayerOnePlaying{true}, playerOne{new ConcreteGame{true}}, playerTwo{new ConcreteGame{false}},
    textDisplay{new TextDisplay{this}}, interpreter{Interpreter{this}} {

    playerOne->setOtherGame(playerTwo); // Give players access to other player
    playerTwo->setOtherGame(playerOne); // for special actions
}

void Biquadris::updateDisplay() {
    textDisplay->displayBoard();
}

void Biquadris::run() {
    playerOne->createBlock();
    playerTwo->createBlock();

    updateDisplay();1

    string command;
    while (cin >> command) {
        interpreter.interpretCommand(command);
        updateDisplay();
    }
}

void Biquadris::switchPlayers() {
    getCurrentPlayer()->createBlock(); // Create new block for current player as other player already has a block
    isPlayerOnePlaying = !isPlayerOnePlaying;
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
