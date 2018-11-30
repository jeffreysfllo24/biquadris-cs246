#ifndef GRAPHICSDISPLAY_H
#define GRAPHICSDISPLAY_H

#include "displayobserver.h"
#include "board.h"
#include "window.h"

class GraphicsDisplay : public DisplayObserver {
    Biquadris * biquadris;
    Xwindow * xw;

    void printBoards(Board &, Board &);
public:
    GraphicsDisplay(Biquadris *);
    ~GraphicsDisplay();
    void displayBoard() override;
};

#endif
