#ifndef DISPLAYOBSERVER_H
#define DISPLAYOBSERVER_H

class Biquadris;

class DisplayObserver {
    Biquadris * biquadrisGame;
public:
    virtual void displayBoard() = 0;
};

#endif //DISPLAYOBSERVER_H
