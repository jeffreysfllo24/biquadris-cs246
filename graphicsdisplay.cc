#include "graphicsdisplay.h"
#include "biquadris.h"
#include "abstractgame.h"
#include <string>

using namespace std;

void printScores(int firstPlayerScore, int secondPlayerScore) {}

void printLevels(int firstPlayerLevel, int secondPlayerLevel) {}

void printBoards(Board & firstPlayerBoard, Board & secondPlayerBoard) {}

void printDivider() {}

void printNext() {}

void printBlockTop(char block) {}

void printBlockBottom(char block) {}

void printBlocks(char firstPlayerBlock, char secondPlayerBlock) {}

GraphicsDisplay::GraphicsDisplay(Biquadris * biquadris):
    biquadris{biquadris} {}

void GraphicsDisplay::displayBoard() {}
