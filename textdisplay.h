#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H

#include "displayobserver.h"

class TextDisplay : public DisplayObserver {
    Biquadris * biquadrisGame;
private:
    void displayBoard() override;
};

#endif //TEXTDISPLAY_H
