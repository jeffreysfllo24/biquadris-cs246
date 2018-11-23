#include "concretegame.h"
#include "level.h"
#include "score.h"

ConcreteGame::ConcreteGame():
    levelInt{0}, level{nullptr}, otherGame{nullptr} {}

void ConcreteGame::setOtherGame(AbstractGame * otherGame) {
    this->otherGame = otherGame;
}

void ConcreteGame::createBlock() {
    Block * newBlock = level->generateBlock();
    // board.createBlock(Block *); // TODO Jeffrey
}

void ConcreteGame::createSpecificBlock(char) {

}