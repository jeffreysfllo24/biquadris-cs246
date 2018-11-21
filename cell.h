#ifndef cell_hpp
#define cell_hpp

class Cell {
    int livesCounter;
    const int xCoord;
    const int yCoord;
    bool hasLetter;
    bool hasSet;
    char letter;
    public:
        Cell(int x, int y);
        bool isSet();
        bool isFilled();
        int getX();
        int getY();
        char getLetter();
        void setLetter(const char &);
        ~Cell();
};

#endif /* cell_hpp */
