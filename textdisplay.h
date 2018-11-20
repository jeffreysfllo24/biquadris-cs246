#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H

#include "displayobserver.h"

class TextDisplay : public DisplayObserver {
private:
    void notify();
};

#endif //TEXTDISPLAY_H
