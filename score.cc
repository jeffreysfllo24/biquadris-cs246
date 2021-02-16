#include "score.h"

Score::Score(): currentScore{0}, highScore{0} {}

void Score::addScore(int score) {
    currentScore += score;
    if (currentScore > highScore) {
        highScore = currentScore;
    }
}

int Score::getCurrentScore() {
    return currentScore;
}

int Score::getHighScore() {
    return highScore;
}

void Score::resetScore() {
    currentScore = 0;
}
