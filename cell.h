#ifndef cell_hpp
#define cell_hpp

#include "coordinate.h"

class Cell {
    Coordinate coord;
    bool hasLetter;
    char letter;
    public:
        Cell(Coordinate &);
        bool isFilled();
        char getLetter();
        void setLetter(const char &);
        ~Cell();
};

#endif /* cell_hpp */
