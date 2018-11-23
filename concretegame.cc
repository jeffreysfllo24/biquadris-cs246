#include "concretegame.h"
#include "level.h"
#include "level0.h"
#include "score.h"

ConcreteGame::ConcreteGame(bool isPlayerOne):
    isPlayerOne{isPlayerOne}, levelInt{0}, level{new Level0{"sequence1.txt"}}, otherGame{nullptr} {}

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

void ConcreteGame::restart() {
    board.clearBoard();
    score.resetScore();
}

Board & ConcreteGame::getBoard() {
    return board;
}