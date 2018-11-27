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

int getMultiplier(string & command) {
    string multiplierString;
    for (int i = 0; i < command.length(); i++) { // remove multiplier number from command
        char currChar = command[i];
        if (currChar >= '0' && currChar <= '9') {
            multiplierString += currChar;
        } else {
            command = command.substr(i, command.length() - i);
            break;
        }
    }
    // Multiplier is taken from input if numbers were inputted and 0 otherwise
    if (multiplierString.length() > 0) {
        return stoi(multiplierString);
    } else {
        return 1;
    }
}

void Interpreter::runLeft(int multiplier) {
    Block * currentBlock = biquadris->getCurrentPlayer()->getBoard().getCurrentBlock();
    for (int i = 0; i < multiplier; i++) {
        currentBlock->left();
    }
}

void Interpreter::runRight(int multiplier) {
    Block * currentBlock = biquadris->getCurrentPlayer()->getBoard().getCurrentBlock();
    for (int i = 0; i < multiplier; i++) {
        currentBlock->right();
    }
}

void Interpreter::runDown(int multiplier) {
    Block * currentBlock = biquadris->getCurrentPlayer()->getBoard().getCurrentBlock();
    for (int i = 0; i < multiplier; i++) {
        currentBlock->down();
    }
}

void Interpreter::runClockwise(int multiplier) {
    Block * currentBlock = biquadris->getCurrentPlayer()->getBoard().getCurrentBlock();
    for (int i = 0; i < multiplier; i++) {
        currentBlock->clockwise();
    }
}

void Interpreter::runCounterclockwise(int multiplier) {
    Block * currentBlock = biquadris->getCurrentPlayer()->getBoard().getCurrentBlock();
    for (int i = 0; i < multiplier; i++) {
        currentBlock->counterclockwise();
    }
}

void Interpreter::runDrop(int multiplier) {
    for (int i = 0; i < multiplier; i++) {
        if (biquadris->getIsGameOver()) { // Check game over every iteration
            return;
        }
        // Get board every time to use other board
        biquadris->getCurrentPlayer()->dropBlock();
        biquadris->switchPlayers();
    }
}

void Interpreter::runLevelUp(int multiplier) {
    for (int i = 0; i < multiplier; i++) {
        biquadris->getCurrentPlayer()->levelUp();
    }
}

void Interpreter::runLevelDown(int multiplier) {
    for (int i = 0; i < multiplier; i++) {
        biquadris->getCurrentPlayer()->levelDown();
    }
}

void Interpreter::interpretCommand(string command) {
    // getMultiplier returns the multiplier and modifies command to remove the numbers
    int multiplier = getMultiplier(command);

    Interpreter::Command chosenCommand = noCommand; // Set default command if no command matches

    bool commandFound = false; // Keep track of command matches and cancel command if there is ambiguity
    for (auto & x : commandMap) { // look for command in the commandMap
        if (command == x.first.substr(0, command.length())) {
            chosenCommand = x.second;
            if (commandFound) {
                cerr << "ambiguous command" << endl;
                return;
            }
            commandFound = true;
        }
    }

    if (biquadris->getIsGameOver()) { // If in game over state, the only allowed action is restart
        if (chosenCommand == restart) {
            biquadris->getFirstPlayer()->restart();
            biquadris->getSecondPlayer()->restart();
        } else {
            cout << "invalid command, game over";
            return;
        }
    }

    switch (chosenCommand) {
        case Interpreter::left:
            runLeft(multiplier);
            break;
        case Interpreter::right:
            runRight(multiplier);
            break;
        case Interpreter::down:
            runDown(multiplier);
            break;
        case Interpreter::clockwise:
            runClockwise(multiplier);
            break;
        case Interpreter::counterclockwise:
            runCounterclockwise(multiplier);
            break;
        case Interpreter::drop:
            runDrop(multiplier);
            break;
        case Interpreter::levelup:
            runLevelUp(multiplier);
            break;
        case Interpreter::leveldown:
            runLevelDown(multiplier);
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
