#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <string>
#include <vector>

// Forward Declaration
class Biquadris;

class Interpreter {
    std::vector<std::string> commandList;
public:
    Interpreter();
    void interpretCommand(std::string, Biquadris &);
};

#endif //INTERPRETER_H
