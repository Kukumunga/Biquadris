CXX = g++-5
CXXFLAGS = -std=c++14 -Werror=vla -Wall -MMD
EXEC = game
OBJECTS = coord.o player.o cell.o grid.o level0.o board.o level.o block.o blocki.o blockj.o blocks.o blockz.o blockt.o blockl.o blocko.o basecommand.o biquadris.o interpreter.o main.o level1.o level2.o window.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -L/usr/X11R6/lib -lX11

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
