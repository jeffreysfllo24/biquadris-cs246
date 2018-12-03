#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <string>
#include <map>

// Forward Declaration
class Biquadris;

class Interpreter {
private:
    enum Command { noCommand, left, right, down, clockwise, counterclockwise, drop, levelup, leveldown, norandom,
        random, sequence, I, J, L, O, S, T, Z, restart, rename,help};
    std::map<std::string, Interpreter::Command> commandMap;
    Biquadris * biquadris;

    void runLeft(int);
    void runRight(int);
    void runDown(int);
    void runClockwise(int);
    void runCounterclockwise(int);
    void promptSpecialAction();
    void runDrop(int);
    void runLevelUp(int);
    void runLevelDown(int);
public:
    Interpreter(Biquadris *);
    void interpretCommand(std::string);
};

#endif //INTERPRETER_H
