#include "concretegame.h"

ConcreteGame::ConcreteGame():
    levelInt{0}, level{nullptr}, otherGame{nullptr} {}

void ConcreteGame::takeTurn() {
    /*board.setPlaying();
    while (board.isPlaying()) {
        if (!board.isAlive()) {
            // end the game
        }
    }*/
}

void ConcreteGame::restart() {
    board.clearBoard();
    // score.resetScore();
}