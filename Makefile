CXX = g++-5
CXXFLAGS = -std=c++14 -Werror=vla -Wall -MMD
EXEC = biquad
OBJECTS = coord.o player.o cell.o grid.o level0.o board.o level.o block.o blocki.o blockj.o blocks.o blockz.o blockt.o blockl.o blocko.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
