#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H

#include "displayobserver.h"

class TextDisplay : public DisplayObserver {
public:
    TextDisplay(Biquadris *);
    void displayBoard() override;
};

#endif //TEXTDISPLAY_H
