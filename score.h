#ifndef SCORE_H
#define SCORE_H

class Score {
    int currentScore;
    int highScore;
public:
    Score();
    void addScore(int);
    int getCurrentScore();
    int getHighScore();
    void resetScore();
};

#endif //SCORE_H
