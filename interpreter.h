#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <string>
#include <map>

// Forward Declaration
class Biquadris;

class Interpreter {
private:
    enum Command { noCommand, left, right, down, clockwise, counterclockwise, drop, levelup, leveldown, norandom,
        random, sequence, I, J, L, O, S, T, Z, restart };
    std::map<std::string, Interpreter::Command> commandList;
    Biquadris * biquadris;
public:
    Interpreter(Biquadris *);
    void interpretCommand(std::string);
};

#endif //INTERPRETER_H
