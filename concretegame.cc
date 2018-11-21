#include "concretegame.h"
#include "level.h"

ConcreteGame::ConcreteGame():
    levelInt{0}, level{nullptr}, otherGame{nullptr} {}

void ConcreteGame::createBlock() {
    Block * newBlock = level->generateBlock();
    // board.createBlock();
}

void ConcreteGame::restart() {
    board.clearBoard();
    // score.resetScore();
}