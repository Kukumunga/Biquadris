#ifndef __BLOCK__I
#define __BLOCK__I
#include "block.h"
#include <vector>
#include <string>

class Coord;
class BlockI : public Block {
public:
	BlockI();
	std::string getType();
	std::vector<Coord> rotateClock();
	std::vector<Coord> rotateCounterClock();
	void executeClock();
	void executeCounterClock();
};

#endif
