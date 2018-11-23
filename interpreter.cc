#include <string>
#include <stdlib.h>
#include <iostream>

#include "interpreter.h"
#include "biquadris.h"
#include "abstractgame.h"

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


void Interpreter::interpretCommand(std::string command) {
    Interpreter::Command chosenCommand = noCommand;

    for (auto & x : commandList) {
        if (command == x.first) {
            chosenCommand = x.second;
        }
    }

    switch (chosenCommand) {
        case Interpreter::left:
            biquadris->getCurrentPlayer()->getBoard().getCurrentBlock()->left();
            break;
        case Interpreter::right:
            biquadris->getCurrentPlayer()->getBoard().getCurrentBlock()->right();
            break;
        case Interpreter::down:
            biquadris->getCurrentPlayer()->getBoard().getCurrentBlock()->down();
            break;
        case Interpreter::clockwise:
            biquadris->getCurrentPlayer()->getBoard().getCurrentBlock()->clockwise();
            break;
        case Interpreter::counterclockwise:
            biquadris->getCurrentPlayer()->getBoard().getCurrentBlock()->counterclockwise();
            break;
        case Interpreter::drop:
            biquadris->getCurrentPlayer()->getBoard().getCurrentBlock()->drop();
            break;
        case Interpreter::levelup:
            break;
        case Interpreter::leveldown:
            break;
        case Interpreter::norandom: {
            string file;
            if (cin >> file) {
                // do something with file
            }
            break;
        }
        case Interpreter::random:
            break;
        case Interpreter::sequence: {
            string file;
            if (cin >> file) {
                // do something with file
            }
            break;
        }
        case Interpreter::I:
            biquadris->getCurrentPlayer()->createSpecificBlock('I');
            break;
        case Interpreter::J:
            biquadris->getCurrentPlayer()->createSpecificBlock('J');
            break;
        case Interpreter::L:
            biquadris->getCurrentPlayer()->createSpecificBlock('L');
            break;
        case Interpreter::O:
            biquadris->getCurrentPlayer()->createSpecificBlock('O');
            break;
        case Interpreter::S:
            biquadris->getCurrentPlayer()->createSpecificBlock('S');
            break;
        case Interpreter::T:
            biquadris->getCurrentPlayer()->createSpecificBlock('T');
            break;
        case Interpreter::Z:
            biquadris->getCurrentPlayer()->createSpecificBlock('Z');
            break;
        case Interpreter::restart:
            break;
        default:
            cerr << "bad command";
            break;
    }

    // TODO: allow for "autocomplete" commands
    // TODO: allow for repeated commands
    // TODO: extension for renaming commands
}