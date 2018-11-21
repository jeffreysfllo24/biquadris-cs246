#include "abstractgame.h"

void AbstractGame::setOtherGame(AbstractGame * otherGame) {
    this->otherGame = otherGame;
}

Board & AbstractGame::getBoard() {
    return board;
}