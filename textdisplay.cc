#include "textdisplay.h"
#include "biquadris.h"
#include "abstractgame.h"
#include <string>
using namespace std;

void printScores(int firstPlayerScore, int secondPlayerScore) {
    string res = "Score:    ";
    cout << res << firstPlayerScore;
    cout << "       "; //TODO Dynamic spacing for more than 1 digit
    cout << res << secondPlayerScore;
    cout << endl;
}

void printLevels(int firstPlayerLevel, int secondPlayerLevel){
    string res = "Level:    ";
    cout << res << firstPlayerLevel;
    cout << "       ";
    cout << res << secondPlayerLevel;
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

void TextDisplay::displayBoard() {
    printLevels(biquadris->getFirstPlayer()->getLevel(),
                biquadris->getSecondPlayer()->getLevel());
    printScores(biquadris->getFirstPlayer()->getScore().getCurrentScore(),
                biquadris->getSecondPlayer()->getScore().getCurrentScore());
    printDivider();
    printBoards(biquadris->getFirstPlayer()->getBoard(),
                biquadris->getSecondPlayer()->getBoard());
    printDivider();
    printNext();
    printBlocks(biquadris->getFirstPlayer()->getBoard().getNextBlock()->getType()[0],   // get block type, convert
                biquadris->getSecondPlayer()->getBoard().getNextBlock()->getType()[0]); // string to char
}


