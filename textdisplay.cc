#include "textdisplay.h"
#include "biquadris.h"
#include "abstractgame.h"
#include <string>
using namespace std;

void printScore(AbstractGame * myGame){
    string res = "Score:    ";
    int scoreVal = myGame->getScore().getCurrentScore();
    res += to_string(scoreVal);
    cout << res;
}

void printLevel(AbstractGame * myGame){
    string res = "Level:    ";
    int levelVal = myGame->getLevel();
    res += to_string(levelVal);
    cout << res;
}

TextDisplay::TextDisplay(Biquadris * biquadris):
    biquadris{biquadris} {}

void TextDisplay::displayBoard() {
    
    Board & firstPlayerBoard = biquadris->getFirstPlayer()->getBoard();
    Board & secondPlayerBoard = biquadris->getSecondPlayer()->getBoard();
    
    //Print Level
    printScore(biquadris->getFirstPlayer());
    cout << "   ";
    printScore(biquadris->getSecondPlayer());
    cout << endl;
    
    //Print Score
    printScore(biquadris->getFirstPlayer());
    cout << "   ";
    printScore(biquadris->getSecondPlayer());
    cout << endl;
    
    
    for(int i = 0; i < 18; ++i){
        string line = "";
        line += firstPlayerBoard.getLine(i);
        line += "       ";
        line += secondPlayerBoard.getLine(i);
        cout << line << endl;
    }
}


