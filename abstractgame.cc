#include "abstractgame.h"

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

AbstractGame::~AbstractGame() = default;
