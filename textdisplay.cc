#include "textdisplay.h"
#include "biquadris.h"
#include "abstractgame.h"
#include <string>
using namespace std;

void TextDisplay::printHelp(){
    cout << "Tips and Tricks:" << endl;
    cout << "1. Understand the spacial relationship between the piece that you want to drop and the current landscape of the play space." << endl;
    cout << "2. Use the next piece indicator to your advantage! Before that piece appears in the play space you should know exactly where it belongs." << endl;
    cout << "3. Know your controls! Ensure that you are familiar with all possible actions and that you understand how each action effects the block on your board. Knowing what to type based on where you want to place the block should be second nature." << endl;
    cout << "4. The most important tip is have fun! As long as you enjoy playing the game you're a winner :)"<< endl;
}

void printLevels(int firstPlayerLevel, int secondPlayerLevel){
    string res = "Level:    ";
    cout << res << firstPlayerLevel;
    cout << "       ";
    cout << res << secondPlayerLevel;
    cout << endl;
}

void printScores(int firstPlayerScore, int secondPlayerScore) {
    string res = "Score: ";

    string firstScore = to_string(firstPlayerScore);
    while (firstScore.length() < 4) {
        firstScore = " " + firstScore;
    }
    cout << res << firstScore;

    cout << "       ";

    string secondScore = to_string(secondPlayerScore);
    while (secondScore.length() < 4) {
        secondScore = " " + secondScore;
    }
    cout << res << secondScore;

    cout << endl;
}

void printHighScores(int firstPlayerHighScore, int secondPlayerHighScore) {
    string res = "High: ";

    string firstScore = to_string(firstPlayerHighScore);
    while (firstScore.length() < 5) {
        firstScore = " " + firstScore;
    }
    cout << res << firstScore;

    cout << "       ";

    string secondScore = to_string(secondPlayerHighScore);
    while (secondScore.length() < 5) {
        secondScore = " " + secondScore;
    }
    cout << res << secondScore;

    cout << endl;
}

void printBoards(Board & firstPlayerBoard, Board & secondPlayerBoard) {
    for(int i = 0; i < 18; ++i){
        cout << firstPlayerBoard.getLine(i);
        cout << "       ";
        cout << secondPlayerBoard.getLine(i);
        cout << endl;
    }
}

void printDivider(){
    cout << "-----------" ;
    cout << "       ";
    cout << "-----------";
    cout << endl;
}

void printNext(){
    cout << "Next:      ";
    cout << "       ";
    cout << "Next:      ";
    cout << endl;
}

void printBlockTop(char block) {
    if (block == 'I') {
        cout << "           ";
    } else if (block == 'J') {
        cout << "J          ";
    } else if (block == 'L') {
        cout << "  L        ";
    } else if (block == 'O') {
        cout << "OO         ";
    } else if (block == 'S') {
        cout << " SS        ";
    } else if (block == 'T') {
        cout << "TTT        ";
    } else { // if (currBlock == 'Z') {
        cout << "ZZ        ";
    }
}

void printBlockBottom(char block) {
    if (block == 'I') {
        cout << "IIII       ";
    } else if (block == 'J') {
        cout << "JJJ        ";
    } else if (block == 'L') {
        cout << "LLL        ";
    } else if (block == 'O') {
        cout << "OO         ";
    } else if (block == 'S') {
        cout << "SS         ";
    } else if (block == 'T') {
        cout << " T         ";
    } else { // if (currBlock == 'Z') {
        cout << " ZZ        ";
    }
};

void printBlocks(char firstPlayerBlock, char secondPlayerBlock) {
    printBlockTop(firstPlayerBlock);
    cout << "       ";
    printBlockTop(secondPlayerBlock);
    cout << endl;
    printBlockBottom(firstPlayerBlock);
    cout << "       ";
    printBlockBottom(secondPlayerBlock);
    cout << endl;
}

TextDisplay::TextDisplay(Biquadris * biquadris):
    biquadris{biquadris} {}

TextDisplay::~TextDisplay() = default;

void TextDisplay::displayBoard() {
    printLevels(biquadris->getFirstPlayer()->getLevel(),
                biquadris->getSecondPlayer()->getLevel());
    printScores(biquadris->getFirstPlayer()->getScore().getCurrentScore(),
                biquadris->getSecondPlayer()->getScore().getCurrentScore());
    printHighScores(biquadris->getFirstPlayer()->getScore().getHighScore(),biquadris->getSecondPlayer()->getScore().getHighScore());
    printDivider();
    printBoards(biquadris->getFirstPlayer()->getBoard(),
                biquadris->getSecondPlayer()->getBoard());
    printDivider();
    printNext();
    printBlocks(biquadris->getFirstPlayer()->getBoard().getNextBlock()->getType()[0],   // get block type, convert
                biquadris->getSecondPlayer()->getBoard().getNextBlock()->getType()[0]); // string to char
}


