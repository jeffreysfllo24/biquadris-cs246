#include "abstractgame.h"
#include "level.h"
#include "level0.h"
#include "level1.h"
#include "level2.h"
#include "level3.h"
#include "level4.h"

using namespace std;

void AbstractGame::levelUp() {
    if (levelInt == 4) {
        return;
    }

    levelInt++;
    board.setLevel(levelInt);
    switch (levelInt) {
        case 1:
            delete level;
            level = new Level1{};
            break;
        case 2:
            delete level;
            level = new Level2{};
            break;
        case 3:
            delete level;
            level = new Level3{};
            break;
        case 4:
            delete level;
            level = new Level4{};
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
    board.setLevel(levelInt);
    switch (levelInt) {
        case 0:
            delete level;
            level = new Level0{isPlayerOne};
            break;
        case 1:
            delete level;
            level = new Level1{};
            break;
        case 2:
            delete level;
            level = new Level2{};
            break;
        case 3:
            delete level;
            level = new Level3{};
            break;
        default:
            break;
    }
}

void AbstractGame::restart() {
    board.clearBoard();
    score.resetScore();

    delete level;
    level = new Level0{isPlayerOne};
}

void AbstractGame::norandom(string filename) {
    level->norandom(filename);
}

void AbstractGame::random() {
    level->random();
}

void AbstractGame::dropBlock(){ // called from interpreter
    int pointsScored = board.dropBlock();
    score.addScore(pointsScored);
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

