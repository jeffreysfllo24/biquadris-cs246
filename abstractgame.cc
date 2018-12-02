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
            level->setSeed(seed);
            break;
        case 2:
            delete level;
            level = new Level2{};
            level->setSeed(seed);
            break;
        case 3:
            delete level;
            level = new Level3{};
            level->setSeed(seed);
            break;
        case 4:
            delete level;
            level = new Level4{};
            level->setSeed(seed);
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
            level = new Level0{isPlayerOne,sequence1,sequence2};
            level->setSeed(seed);
            break;
        case 1:
            delete level;
            level = new Level1{};
            level->setSeed(seed);
            break;
        case 2:
            delete level;
            level = new Level2{};
            level->setSeed(seed);
            break;
        case 3:
            delete level;
            level = new Level3{};
            level->setSeed(seed);
            break;
        default:
            break;
    }
}

void AbstractGame::restart() {
    board.clearBoard();
    score.resetScore();

    delete level;
    level = new Level0{isPlayerOne,sequence1,sequence2};
}

void AbstractGame::norandom(string filename) {
    level->norandom(filename);
}

void AbstractGame::random() {
    level->random();
}

int AbstractGame::dropBlock(){ // called from interpreter
    int linesCleared = 0;
    int pointsScored = board.dropBlock(linesCleared);
    score.addScore(pointsScored);

    return linesCleared;
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

void AbstractGame::setLevel(int newLevel){
    levelInt = newLevel;
    board.setLevel(levelInt);
    switch (levelInt) {
        case 0:
            delete level;
            level = new Level0{isPlayerOne,sequence1,sequence2};
            break;
        case 1:
            delete level;
            level = new Level1{};
            level->setSeed(seed);
            break;
        case 2:
            delete level;
            level = new Level2{};
            level->setSeed(seed);
            break;
        case 3:
            delete level;
            level = new Level3{};
            level->setSeed(seed);
            break;
        default:
            break;
    }
}

void AbstractGame::setSequences(string newSequence1,string newSequence2){
    sequence1 = newSequence1;
    sequence2 = newSequence2;
}

void AbstractGame::setSeed(int seedVal){
    seed = seedVal;
}

AbstractGame::~AbstractGame() = default;

