#include <string>
#include <vector>

#include "interpreter.h"
#include "biquadris.h"

Interpreter::Interpreter():
    commandList{{"left", "right"}} {} // TODO: add all commands

void Interpreter::interpretCommand(std::string command, Biquadris & bq) {
    if (command == "left") {
        // perform left rotation
    } else if (command == "right") {
        // perform right rotation
    }
    // TODO: allow for "autocomplete" commands
    // TODO: allow for repeated commands
    // TODO: extension for renaming commands
}