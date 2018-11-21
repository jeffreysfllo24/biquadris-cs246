#include <string>
#include <stdlib.h>
#include <iostream>

#include "interpreter.h"
#include "biquadris.h"

using namespace std;

Interpreter::Interpreter(Biquadris * biquadris):
    biquadris{biquadris},
    commandList{{"left", Interpreter::left},
                {"right", Interpreter::right},
                {"down", Interpreter::down},
                {"clockwise", Interpreter::clockwise},
                {"counterclockwise", Interpreter::counterclockwise},
                {"drop", Interpreter::drop},
                {"levelup", Interpreter::levelup},
                {"leveldown", Interpreter::leveldown},
                {"norandom", Interpreter::norandom},
                {"random", Interpreter::random},
                {"sequence", Interpreter::sequence},
                {"I", Interpreter::I},
                {"J", Interpreter::J},
                {"L", Interpreter::L},
                {"O", Interpreter::O},
                {"S", Interpreter::S},
                {"T", Interpreter::T},
                {"Z", Interpreter::Z},
                {"restart", Interpreter::restart}} {}

void Interpreter::runInterpreter() {
    string s;
    while(cin >> s) {
        interpretCommand(s);
    }
}

void Interpreter::interpretCommand(std::string command) {
    Interpreter::Command chosenCommand = noCommand;

    for (auto & x : commandList) {
        if (command == x.first) {
            chosenCommand = x.second;
        }
    }

    switch (chosenCommand) {
        case left:
            break;
        case right:
            break;
        case down:
            break;
        case clockwise:
            break;
        case counterclockwise:
            break;
        case drop:
            break;
        case levelup:
            break;
        case leveldown:
            break;
        case norandom: {
            string file;
            if (cin >> file) {
                // do something with file
            }
            break;
        }
        case random:
            break;
        case sequence: {
            string file;
            if (cin >> file) {
                // do something with file
            }
            break;
        }
        case I:
            break;
        case J:
            break;
        case L:
            break;
        case O:
            break;
        case S:
            break;
        case T:
            break;
        case Z:
            break;
        case restart:
            break;
        default:
            cerr << "bad command";
            break;
    }
    // TODO: allow for "autocomplete" commands
    // TODO: allow for repeated commands
    // TODO: extension for renaming commands
}