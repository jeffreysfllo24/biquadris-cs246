#include "graphicsdisplay.h"
#include "biquadris.h"
#include "abstractgame.h"
#include <string>

using namespace std;

// void printScores(int firstPlayerScore, int secondPlayerScore) {}

// void printLevels(int firstPlayerLevel, int secondPlayerLevel) {}

int getCellColour(char block) {
    if (block == 'I') {
        return Xwindow::Black;
    } else if (block == 'J') {
        return Xwindow::Black;
    } else if (block == 'L') {
        return Xwindow::Black;
    } else if (block == 'O') {
        return Xwindow::Black;
    } else if (block == 'S') {
        return Xwindow::Black;
    } else if (block == 'T') {
        return Xwindow::Black;
    } else if (block == 'Z') {
        return Xwindow::Black;
    } else {
        return Xwindow::White;
    }
}

void GraphicsDisplay::printBoards(Board & firstPlayerBoard, Board & secondPlayerBoard) {
    const int cellWidth = 700 / 28;
    const int cellHeight = 650 / 26;
    for (int i = 0; i < 18; ++i) {
        string firstBoardLine = firstPlayerBoard.getLine(i);
        string secondBoardLine = secondPlayerBoard.getLine(i);
        for (int j = 0; j < firstBoardLine.length(); ++j) {
            xw->fillRectangle(j, i+3, cellWidth, cellHeight, getCellColour(firstBoardLine[j]));
        }
        for (int j = 0; j < secondBoardLine.length(); ++j) {
            xw->fillRectangle(j+6, i+3, cellWidth, cellHeight, getCellColour(secondBoardLine[j]));
        }
    }
}

// void printDivider() {}

// void printNext() {}

// void printBlockTop(char block) {}

// void printBlockBottom(char block) {}

// void printBlocks(char firstPlayerBlock, char secondPlayerBlock) {}

GraphicsDisplay::GraphicsDisplay(Biquadris * biquadris):
    biquadris{biquadris} {
        xw = new Xwindow;
    }

GraphicsDisplay::~GraphicsDisplay() {
    delete xw;
}

void GraphicsDisplay::displayBoard() {
    printBoards(biquadris->getFirstPlayer()->getBoard(),
                biquadris->getSecondPlayer()->getBoard());
}
