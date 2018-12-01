CXX = g++
CXXFLAGS = -std=c++14 -Wall -g -Werror=vla -I/usr/X11R6/include/
OBJECTS = main.o cell.o block.o iblock.o jblock.o lblock.o oblock.o sblock.o tblock.o zblock.o starblock.o board.o level.o level0.o level1.o level2.o level3.o level4.o score.o abstractgame.o concretegame.o interpreter.o displayobserver.o textdisplay.o window.o graphicsdisplay.o biquadris.o
EXEC = quadris
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -L/usr/X11R6/lib -lX11

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${EXEC} ${OBJECTS}
