#include "concretegame.h"
#include "level.h"
#include "level0.h"
#include "score.h"

using namespace std;

ConcreteGame::ConcreteGame(bool isPlayerOne,string sequence1, string sequence2) {
    this->isPlayerOne = isPlayerOne;
    this->levelInt = 0;
    this->setSequences(sequence1, sequence2);
    this->level = new Level0{isPlayerOne,sequence1,sequence2};
}


void ConcreteGame::createBlock() {
    Block * newBlock = level->generateBlock();
    board.createBlock(newBlock);
}

void ConcreteGame::replaceSpecificBlock(char blockChar) {
    Block * newBlock = level->createSpecificBlock(blockChar, levelInt);
    board.replaceBlock(newBlock);
}
