#ifndef GRAPHICSDISPLAY_H
#define GRAPHICSDISPLAY_H

#include "displayobserver.h"

class GraphicsDisplay : public DisplayObserver {
    Biquadris * biquadris;
public:
    GraphicsDisplay(Biquadris *);
    void displayBoard() override;
};

#endif
