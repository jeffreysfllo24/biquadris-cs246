#include "concretegame.h"
#include "level.h"
#include "level0.h"
#include "score.h"

using namespace std;

ConcreteGame::ConcreteGame(bool isPlayerOne) {
    this->isPlayerOne = isPlayerOne;
    this->levelInt = 0;
    string s = isPlayerOne ? "sequence1.txt" : "sequence2.txt"; // set sequence based on player
    this->level = new Level0{s};
    this->otherGame = nullptr;
}

void ConcreteGame::setOtherGame(AbstractGame * otherGame) {
    this->otherGame = otherGame;
}

void ConcreteGame::createBlock() {
    Block * newBlock = level->generateBlock();
    board.createBlock(newBlock);
}

void ConcreteGame::createSpecificBlock(char blockChar) {
    Block * newBlock = level->createSpecificBlock(blockChar);
    board.createBlock(newBlock);
}
