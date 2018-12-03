#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H

#include "displayobserver.h"

class TextDisplay : public DisplayObserver {
    Biquadris * biquadris;
public:
    TextDisplay(Biquadris *);
    ~TextDisplay() override;
    void displayBoard() override;
    void printHelp() override;
};

#endif //TEXTDISPLAY_H
