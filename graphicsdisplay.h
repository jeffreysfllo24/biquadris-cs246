#ifndef GRAPHICSDISPLAY_H
#define GRAPHICSDISPLAY_H

#include "displayobserver.h"
#include "window.h"
#include "biquadris.h"
#include "abstractgame.h"

class GraphicsDisplay : public DisplayObserver {
    Biquadris * biquadris;
    Xwindow * xw;
    void printTitle();
    void printLevels(int, int);
    void printScores(int, int);
    void printHighScores(int, int);
    void printBoard();
    void unDraw();
    void printBoardBlocks(Board &, Board &);
    void printNextBlock(int, int, char);
    void printNext(char, char);
    void printResult(int, int);
public:
    GraphicsDisplay(Biquadris *);
    void printHelp() override;
    ~GraphicsDisplay() override;
    void displayBoard() override;
};

#endif
