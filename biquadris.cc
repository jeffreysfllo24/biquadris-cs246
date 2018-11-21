#include "biquadris.h"
#include "concretegame.h"
#include "textdisplay.h"

using namespace std;

Biquadris::Biquadris():
    isPlayerOnePlaying{true}, playerOne{new ConcreteGame{}}, playerTwo{new ConcreteGame{}},
    textDisplay{new TextDisplay}, interpreter{Interpreter{this}} {}

void Biquadris::updateDisplay() {

}

void Biquadris::run() {
    string command;
    while (cin >> command) {
        interpreter.interpretCommand(command);
    }
}

AbstractGame * Biquadris::getCurrentPlayer() {
    if (isPlayerOnePlaying) {
        return playerOne;
    } else {
        return playerTwo;
    }
}
