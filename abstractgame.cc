#include "abstractgame.h"
#include "level.h"

void AbstractGame::restart() {
    board.clearBoard();
    score.resetScore();
}

Board & AbstractGame::getBoard() {
    return board;
}

Score & AbstractGame::getScore(){
    return score;
}

int AbstractGame::getLevel(){
    return levelInt;
}

char AbstractGame::getNextBlock() {
    return level->nextBlock();
}

AbstractGame::~AbstractGame() = default;

