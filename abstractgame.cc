#include "abstractgame.h"
#include "level.h"
#include "level0.h"
#include "level1.h"

void AbstractGame::levelUp() {
    if (levelInt == 4) {
        return;
    }

    levelInt++;
    char nextBlock = level->getNextBlock();
    switch (levelInt) {
        case 1:
            delete level;
            level = new Level1{nextBlock, true};
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        default:
            break;
    }
}

void AbstractGame::levelDown() {
    if (levelInt == 0) {
        return;
    }

    levelInt--;
    char nextBlock = level->getNextBlock();
    switch (levelInt) {
        case 0:
            delete level;
            level = new Level0{isPlayerOne, nextBlock, true};
            break;
        case 1:
            delete level;
            level = new Level1{nextBlock, true};
            break;
        case 2:
            break;
        case 3:
            break;
        default:
            break;
    }
}

void AbstractGame::restart() {
    board.clearBoard();
    score.resetScore();
    // TODO reset level sequence?
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
    return level->getNextBlock();
}

void AbstractGame::dropBlock(){
    int pointsScored = board.dropBlock(); //Called from interpreter
    score.addScore(pointsScored);
}

AbstractGame::~AbstractGame() = default;

