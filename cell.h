#ifndef cell_hpp
#define cell_hpp

#include <string>

class Cell {
    int livesCounter;
    const int xCoord;
    const int yCoord;
    std::string letter;
    public:
        Cell(int x, int y);
        bool isFilled();
        int getX();
        int getY();
        std::string getLetter();
        void setLetter(const std::string &);
        ~Cell();
};

#endif /* cell_hpp */
