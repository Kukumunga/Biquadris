CXX = g++-5
CXXFLAGS = -std=c++14 -Werror=vla -Wall -MMD
EXEC = game
OBJECTS = window.o coord.o player.o cell.o grid.o level0.o board.o level.o blockstar.o block.o blocki.o blockj.o blocks.o blockz.o blockt.o blockl.o blocko.o biquadris.o interpreter.o main.o level1.o level2.o level3.o level4.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -L/usr/X11R6/lib -lX11

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
