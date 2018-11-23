#include "biquadris.h"
#include "concretegame.h"
#include "textdisplay.h"

using namespace std;

Biquadris::Biquadris():
    isPlayerOnePlaying{true}, playerOne{new ConcreteGame{}}, playerTwo{new ConcreteGame{}},
    textDisplay{new TextDisplay}, interpreter{Interpreter{this}} {

    playerOne->setOtherGame(playerTwo); // Give players access to other player
    playerTwo->setOtherGame(playerOne); // for special actions
}

void Biquadris::updateDisplay() {
    textDisplay->displayBoard();
}

void Biquadris::run() {
    string command;
    while (cin >> command) {
        interpreter.interpretCommand(command);
        updateDisplay();
    }
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
