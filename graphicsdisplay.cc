#include "graphicsdisplay.h"
#include <string>

using namespace std;

const int cellWidth = 650 / 26;
const int cellHeight = 750 / 30;

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

GraphicsDisplay::GraphicsDisplay(Biquadris * biquadris):
    biquadris{biquadris} {
        xw = new Xwindow;
    }

GraphicsDisplay::~GraphicsDisplay() {
    delete xw;
}

void GraphicsDisplay::displayBoard() {
    printTitle();
    printBoard();
    printLevels(biquadris->getFirstPlayer()->getLevel(),
                biquadris->getSecondPlayer()->getLevel());
    printScores(biquadris->getFirstPlayer()->getScore().getCurrentScore(),
                biquadris->getSecondPlayer()->getScore().getCurrentScore());
    printHighScores(biquadris->getFirstPlayer()->getScore().getHighScore(), biquadris->getSecondPlayer()->getScore().getHighScore());
    printBoardBlocks(biquadris->getFirstPlayer()->getBoard(),
                biquadris->getSecondPlayer()->getBoard());
    printNext(biquadris->getFirstPlayer()->getBoard().getNextBlock()->getType()[0],   // get block type, convert
                biquadris->getSecondPlayer()->getBoard().getNextBlock()->getType()[0]);
}
