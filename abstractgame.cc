#include "abstractgame.h"

void AbstractGame::restart() {
    board.clearBoard();
    score.resetScore();
}

Board & AbstractGame::getBoard() {
    return board;
}

AbstractGame::~AbstractGame() = default;