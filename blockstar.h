#ifndef __BLOCK__STAR
#define __BLOCK__STAR
#include "block.h"
#include <string>
#include <vector>

class Coord;
class BlockStar : public Block {
public:
	BlockStar();
	std::string getType();
	std::vector<Coord> rotateClock();
	std::vector<Coord> rotateCounterClock();
	void executeClock();
	void executeCounterClock();
};

#endif
