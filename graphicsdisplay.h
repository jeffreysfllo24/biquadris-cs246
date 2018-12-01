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
    void printBoardBlocks(Board &, Board &);
    void printNextBlock(int, int, char);
    void printNext(char, char);
public:
    GraphicsDisplay(Biquadris *);
    ~GraphicsDisplay();
    void displayBoard() override;
};

#endif
