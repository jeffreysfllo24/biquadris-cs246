#include <string>
#include <stdlib.h>
#include <iostream>

#include "interpreter.h"
#include "biquadris.h"
#include "abstractgame.h"

using namespace std;

Interpreter::Interpreter(Biquadris * biquadris):
    biquadris{biquadris},
    commandMap{{"left", Interpreter::left},
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

    string multiplierString;
    for (int i = 0; i < command.length(); i++) { // remove multiplier number from command
        char currChar = command[i];
        if (currChar >= '0' && currChar <= '9') {
            multiplierString += currChar;
        } else {
            command = command.substr(i, command.length() - i);
            cout << command;
            break;
        }
    }
    // Multiplier is taken from input if numbers were inputted and 0 otherwise
    int multiplier = multiplierString.length() > 0 ? stoi(multiplierString) : 1;


    for (auto & x : commandMap) { // look for command in the commandMap
        if (command == x.first) {
            chosenCommand = x.second;
        }
    }

    switch (chosenCommand) {
        case Interpreter::left:
            for (int i = 0; i < multiplier; i++) {
                biquadris->getCurrentPlayer()->getBoard().getCurrentBlock()->left();
            }
            break;
        case Interpreter::right:
            for (int i = 0; i < multiplier; i++) {
                biquadris->getCurrentPlayer()->getBoard().getCurrentBlock()->right();
            }
            break;
        case Interpreter::down:
            for (int i = 0; i < multiplier; i++) {
                biquadris->getCurrentPlayer()->getBoard().getCurrentBlock()->down();
            }
            break;
        case Interpreter::clockwise:
            for (int i = 0; i < multiplier; i++) {
                biquadris->getCurrentPlayer()->getBoard().getCurrentBlock()->clockwise();
            }
            break;
        case Interpreter::counterclockwise:
            for (int i = 0; i < multiplier; i++) {
                biquadris->getCurrentPlayer()->getBoard().getCurrentBlock()->counterclockwise();
            }
            break;
        case Interpreter::drop:
            for (int i = 0; i < multiplier; i++) {
                biquadris->getCurrentPlayer()->getBoard().dropBlock();
                biquadris->switchPlayers();
            }
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
            cerr << "bad command" << endl;
            break;
    }

    // TODO: allow for "autocomplete" commands
    // TODO: allow for repeated commands
    // TODO: extension for renaming commands
}
