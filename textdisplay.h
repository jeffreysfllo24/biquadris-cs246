#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H

#include "displayobserver.h"

class TextDisplay : public DisplayObserver {
public:
    TextDisplay(Biquadris *);
    ~TextDisplay() override;
    void displayBoard() override;
    void printHelp() override;
};

#endif //TEXTDISPLAY_H
