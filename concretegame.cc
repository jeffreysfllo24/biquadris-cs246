#include "concretegame.h"
#include "level.h"
#include "level0.h"
#include "score.h"

ConcreteGame::ConcreteGame(bool isPlayerOne) {
    this->isPlayerOne = isPlayerOne;
    this->levelInt = 0;
    this->level = new Level0{"sequence1.txt"};
    this->otherGame = nullptr;
}

void ConcreteGame::setOtherGame(AbstractGame * otherGame) {
    this->otherGame = otherGame;
}

void ConcreteGame::createBlock() {
    Block * newBlock = level->generateBlock();
    // board.createBlock(Block *); // TODO Jeffrey
}

void ConcreteGame::createSpecificBlock(char blockChar) {
    Block * newBlock = level->createSpecificBlock(blockChar);
    // board.createBlock(Block *); // TODO Jeffrey
}
