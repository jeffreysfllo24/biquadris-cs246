#ifndef cell_hpp
#define cell_hpp

#include "coordinate.h"

class Cell {
    const int xcord;
    const int ycord;
    bool hasLetter;
    char letter;
    public:
        Cell(int x, int y);
        bool isFilled();
        char getLetter();
        void setLetter(const char &);
        ~Cell();
};

#endif /* cell_hpp */
