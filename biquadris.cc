#include "biquadris.h"
#include "concretegame.h"
#include "textdisplay.h"

using namespace std;

Biquadris::Biquadris():
    textDisplay{new TextDisplay} {}

void Biquadris::interpretCommand(string command) {
    interpreter.interpretCommand(command, *this);
}


void Biquadris::updateDisplay() {

}