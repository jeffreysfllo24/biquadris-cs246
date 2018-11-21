#include "biquadris.h"
#include "concretegame.h"
#include "textdisplay.h"

using namespace std;

Biquadris::Biquadris():
    textDisplay{new TextDisplay}, interpreter{Interpreter{this}} {}

void Biquadris::run() {
    interpreter.runInterpreter();
}


void Biquadris::updateDisplay() {

}