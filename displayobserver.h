#ifndef DISPLAYOBSERVER_H
#define DISPLAYOBSERVER_H

class Biquadris;

class DisplayObserver {
protected:
    Biquadris * biquadris;
public:
    virtual void displayBoard() = 0;
    virtual void printHelp() = 0;
    virtual ~DisplayObserver() = 0;
};

#endif //DISPLAYOBSERVER_H
