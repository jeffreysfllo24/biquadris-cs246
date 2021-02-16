#ifndef cell_hpp
#define cell_hpp

#include <string>

class Cell {
    int livesCounter;
    const int rowCord;
    const int colCord;
    std::string letter;
    public:
        Cell(int x, int y);
        bool isFilled();
        int getRow();
        int getCol();
        std::string getLetter();
        void setLetter(const std::string &);
        void copyData(Cell * other); //Copies data of other into the cell calling copyData

        ~Cell();
};

#endif /* cell_hpp */
