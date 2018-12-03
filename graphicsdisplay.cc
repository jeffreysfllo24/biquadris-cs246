#include "graphicsdisplay.h"
#include <string>

using namespace std;

const int cellWidth = 572 / 26; // each cell is width and height of 22
const int cellHeight = 880 / 40;

void GraphicsDisplay::printTitle() {
    string res = "BIQUADRIS";
    xw->drawString(1 * cellWidth, 2 * cellHeight, res);
}

void GraphicsDisplay::printLevels(int firstPlayerLevel, int secondPlayerLevel) {
    string res = "Level:       ";
    string firstLevel = res + to_string(firstPlayerLevel);
    string secondLevel = res + to_string(secondPlayerLevel);
    xw->drawString(2 * cellWidth, 4 * cellHeight, firstLevel);
    xw->drawString(15 * cellWidth, 4 * cellHeight, secondLevel);
}

void GraphicsDisplay::printScores(int firstPlayerScore, int secondPlayerScore) {
    string res = "Score: ";
    
    // board one
    string firstScore = to_string(firstPlayerScore);
    while (firstScore.length() < 7) {
        firstScore = " " + firstScore;
    }
    firstScore = res + firstScore;
    xw->drawString(2 * cellWidth, 5 * cellHeight, firstScore);

    // board two
    string secondScore = to_string(secondPlayerScore);
    while (secondScore.length() < 7) {
        secondScore = " " + secondScore;
    }
    secondScore = res + secondScore;
    xw->drawString(15 * cellWidth, 5 * cellHeight, secondScore);
}

void GraphicsDisplay::printHighScores(int firstPlayerHighScore, int secondPlayerHighScore) {
    string res = "High: ";

    // board one
    string firstScore = to_string(firstPlayerHighScore);
    while (firstScore.length() < 8) {
        firstScore = " " + firstScore;
    }
    firstScore = res + firstScore;
    xw->drawString(2 * cellWidth, 6 * cellHeight, firstScore);

    // board two
    string secondScore = to_string(secondPlayerHighScore);
    while (secondScore.length() < 8) {
        secondScore = " " + secondScore;
    }
    secondScore = res + secondScore;
    xw->drawString(15 * cellWidth, 6 * cellHeight, secondScore);
}

int getCellColour(char block) {
    if (block == 'I') {
        return Xwindow::Cyan;
    } else if (block == 'J') {
        return Xwindow::Blue;
    } else if (block == 'L') {
        return Xwindow::Orange;
    } else if (block == 'O') {
        return Xwindow::Yellow;
    } else if (block == 'S') {
        return Xwindow::Green;
    } else if (block == 'T') {
        return Xwindow::Purple;
    } else if (block == 'Z') {
        return Xwindow::Red;
    } else if (block == '?') {
        return Xwindow::White;
    } else { // if (block == '*') {
        return Xwindow::Tan;
    }
}

void GraphicsDisplay::printBoard() {
    // board one
    xw->fillRectangle(1 * cellWidth, 7 * cellHeight, 11 * cellWidth + 2, 18 * cellHeight + 2, Xwindow::Black); // fix magic numbers
    // board two
    xw->fillRectangle(14 * cellWidth, 7 * cellHeight, 11 * cellWidth + 2, 18 * cellHeight + 2, Xwindow::Black); // fix magic numbers
    // scores
    xw->fillRectangle(2 * cellWidth, 3 * cellHeight, 24 * cellWidth, 3 * cellHeight, Xwindow::White);
    // next block areas
    xw->fillRectangle(2 * cellWidth, 27 * cellHeight, 11 * cellWidth + 2, 18 * cellHeight + 2, Xwindow::White); // fix magic numbers
    xw->fillRectangle(15 * cellWidth, 27 * cellHeight, 11 * cellWidth + 2, 18 * cellHeight + 2, Xwindow::White); // fix magic numbers
}

void GraphicsDisplay::printBoardBlocks(Board & firstPlayerBoard, Board & secondPlayerBoard) {
    string firstBoardLine, secondBoardLine;
    for (int i = 0; i < 18; ++i) {
        firstBoardLine = firstPlayerBoard.getLine(i);
        secondBoardLine = secondPlayerBoard.getLine(i);
        for (int j = 0; j < firstBoardLine.length(); ++j) {
            if (firstBoardLine[j] != '.') {
                xw->fillRectangle((j+1) * cellWidth + 2, (i+7) * cellHeight + 2, cellWidth - 2, cellHeight - 2, getCellColour(firstBoardLine[j]));
            }
        }
        for (int j = 0; j < secondBoardLine.length(); ++j) {
            if (secondBoardLine[j] != '.') {
                xw->fillRectangle((j+14) * cellWidth + 2, (i+7) * cellHeight + 2, cellWidth - 2, cellHeight - 2, getCellColour(secondBoardLine[j]));
            }
        }
    }
}

void GraphicsDisplay::printNextBlock(int x, int y, char block) {
    if (block == 'I') {
        xw->fillRectangle(x * cellWidth + 2, (y+1) * cellHeight + 2, cellWidth - 2, cellHeight - 2, getCellColour(block));
        xw->fillRectangle((x+1) * cellWidth + 2, (y+1) * cellHeight + 2, cellWidth - 2, cellHeight - 2, getCellColour(block));
        xw->fillRectangle((x+2) * cellWidth + 2, (y+1) * cellHeight + 2, cellWidth - 2, cellHeight - 2, getCellColour(block));
        xw->fillRectangle((x+3) * cellWidth + 2, (y+1) * cellHeight + 2, cellWidth - 2, cellHeight - 2, getCellColour(block));
    } else if (block == 'J') {
        xw->fillRectangle(x * cellWidth + 2, (y+1) * cellHeight + 2, cellWidth - 2, cellHeight - 2, getCellColour(block));
        xw->fillRectangle((x+1) * cellWidth + 2, (y+1) * cellHeight + 2, cellWidth - 2, cellHeight - 2, getCellColour(block));
        xw->fillRectangle((x+2) * cellWidth + 2, (y+1) * cellHeight + 2, cellWidth - 2, cellHeight - 2, getCellColour(block));
        xw->fillRectangle(x * cellWidth + 2, y * cellHeight + 2, cellWidth - 2, cellHeight - 2, getCellColour(block));
    } else if (block == 'L') {
        xw->fillRectangle(x * cellWidth + 2, (y+1) * cellHeight + 2, cellWidth - 2, cellHeight - 2, getCellColour(block));
        xw->fillRectangle((x+1) * cellWidth + 2, (y+1) * cellHeight + 2, cellWidth - 2, cellHeight - 2, getCellColour(block));
        xw->fillRectangle((x+2) * cellWidth + 2, (y+1) * cellHeight + 2, cellWidth - 2, cellHeight - 2, getCellColour(block));
        xw->fillRectangle((x+2) * cellWidth + 2, y * cellHeight + 2, cellWidth - 2, cellHeight - 2, getCellColour(block));
    } else if (block == 'O') {
        xw->fillRectangle(x * cellWidth + 2, (y+1) * cellHeight + 2, cellWidth - 2, cellHeight - 2, getCellColour(block));
        xw->fillRectangle((x+1) * cellWidth + 2, (y+1) * cellHeight + 2, cellWidth - 2, cellHeight - 2, getCellColour(block));
        xw->fillRectangle(x * cellWidth + 2, y * cellHeight + 2, cellWidth - 2, cellHeight - 2, getCellColour(block));
        xw->fillRectangle((x+1) * cellWidth + 2, y * cellHeight + 2, cellWidth - 2, cellHeight - 2, getCellColour(block));
    } else if (block == 'S') {
        xw->fillRectangle(x * cellWidth + 2, (y+1) * cellHeight + 2, cellWidth - 2, cellHeight - 2, getCellColour(block));
        xw->fillRectangle((x+1) * cellWidth + 2, (y+1) * cellHeight + 2, cellWidth - 2, cellHeight - 2, getCellColour(block));
        xw->fillRectangle((x+1) * cellWidth + 2, y * cellHeight + 2, cellWidth - 2, cellHeight - 2, getCellColour(block));
        xw->fillRectangle((x+2) * cellWidth + 2, y * cellHeight + 2, cellWidth - 2, cellHeight - 2, getCellColour(block));
    } else if (block == 'T') {
        xw->fillRectangle((x+1) * cellWidth + 2, (y+1) * cellHeight + 2, cellWidth - 2, cellHeight - 2, getCellColour(block));
        xw->fillRectangle(x * cellWidth + 2, y * cellHeight + 2, cellWidth - 2, cellHeight - 2, getCellColour(block));
        xw->fillRectangle((x+1) * cellWidth + 2, y * cellHeight + 2, cellWidth - 2, cellHeight - 2, getCellColour(block));
        xw->fillRectangle((x+2) * cellWidth + 2, y * cellHeight + 2, cellWidth - 2, cellHeight - 2, getCellColour(block));
    } else { // if (block == 'Z') {
        xw->fillRectangle((x+1) * cellWidth + 2, (y+1) * cellHeight + 2, cellWidth - 2, cellHeight - 2, getCellColour(block));
        xw->fillRectangle((x+2) * cellWidth + 2, (y+1) * cellHeight + 2, cellWidth - 2, cellHeight - 2, getCellColour(block));
        xw->fillRectangle(x * cellWidth + 2, y * cellHeight + 2, cellWidth - 2, cellHeight - 2, getCellColour(block));
        xw->fillRectangle((x+1) * cellWidth + 2, y * cellHeight + 2, cellWidth - 2, cellHeight - 2, getCellColour(block));
    }
}

void GraphicsDisplay::printNext(char firstPlayerBlock, char secondPlayerBlock) {
    string next = "Next: ";
    // board one
    xw->drawString(2 * cellWidth, 26 * cellHeight, next);
    printNextBlock(2, 27, firstPlayerBlock);
    // board two
    xw->drawString(15 * cellWidth, 26 * cellHeight, next);
    printNextBlock(15, 27, secondPlayerBlock);
}

void GraphicsDisplay::printHelp() {
    string title = "Tips and Tricks: ";
    string tip1 = "1. Understand the spacial relationship between the piece that you";
    string tip1b = "   want to drop and the current landscape of the play space.";
    string tip2 = "2. Use the next piece indicator to your advantage! Before that piece";
    string tip2b = "   appears in the play space you should know exactly where it belongs.";
    string tip3 = "3. Know your controls! Ensure that you are familiar with all possible actions";
    string tip3b = "   and that you understand how each action effects the block on your board.";
    string tip4 = "4. The most important tip is have fun! As long as you enjoy playing";
    string tip4b = "   the game you're a winner! :)";
    xw->drawString(2 * cellWidth, 31 * cellHeight, title);
    xw->drawString(2 * cellWidth, 32 * cellHeight, tip1);
    xw->drawString(2 * cellWidth, 33 * cellHeight, tip1b);
    xw->drawString(2 * cellWidth, 34 * cellHeight, tip2);
    xw->drawString(2 * cellWidth, 35 * cellHeight, tip2b);
    xw->drawString(2 * cellWidth, 36 * cellHeight, tip3);
    xw->drawString(2 * cellWidth, 37 * cellHeight, tip3b);
    xw->drawString(2 * cellWidth, 38 * cellHeight, tip4);
    xw->drawString(2 * cellWidth, 39 * cellHeight, tip4b);
}

void GraphicsDisplay::unDraw(){
    xw->fillRectangle(1 * cellWidth, 30 * cellHeight, 40 * cellWidth, 12 * cellHeight, Xwindow::White);
}

void GraphicsDisplay::printResult(int firstPlayerScore, int secondPlayerScore) { // winner is 0 if player1 wins and 1 if player2 wins
    string gameOver = "GAME OVER";
    string winMessage;
    if (firstPlayerScore == secondPlayerScore) {
        winMessage = "Result is draw!!";
    } else if (firstPlayerScore > secondPlayerScore) {
        winMessage = "Player 1 wins!!!";
    } else {
        winMessage = "Player 2 wins!!!";
    }
    xw->fillRectangle(1 * cellWidth, 7 * cellHeight, 24 * cellWidth + 2, 18 * cellHeight + 2, Xwindow::Red);
    xw->drawString(12 * cellWidth, 15 * cellHeight, gameOver);
    xw->drawString(11 * cellWidth, 16 * cellHeight, winMessage);
} 

GraphicsDisplay::GraphicsDisplay(Biquadris * biquadris):
    biquadris{biquadris} {
        xw = new Xwindow;
    }

GraphicsDisplay::~GraphicsDisplay() {
    delete xw;
}

void GraphicsDisplay::displayBoard() {
    unDraw();
    printTitle();
    printBoard();
    printLevels(biquadris->getFirstPlayer()->getLevel(),
                biquadris->getSecondPlayer()->getLevel());
    printScores(biquadris->getFirstPlayer()->getScore().getCurrentScore(),
                biquadris->getSecondPlayer()->getScore().getCurrentScore());
    printHighScores(biquadris->getFirstPlayer()->getScore().getHighScore(), biquadris->getSecondPlayer()->getScore().getHighScore());
    if (biquadris->getIsGameOver()) {
        printResult(biquadris->getFirstPlayer()->getScore().getCurrentScore(),
                    biquadris->getSecondPlayer()->getScore().getCurrentScore());
    } else {
        printBoardBlocks(biquadris->getFirstPlayer()->getBoard(),
                biquadris->getSecondPlayer()->getBoard());
        printNext(biquadris->getFirstPlayer()->getBoard().getNextBlock()->getType()[0],   // get block type, convert
                biquadris->getSecondPlayer()->getBoard().getNextBlock()->getType()[0]);
    }
}
