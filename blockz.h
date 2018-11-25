#ifndef __BLOCK__Z
#define __BLOCK__Z
#include <vector>
#include <string>
#include "block.h"

class Coord;
class BlockZ : public Block {
public:
	BlockZ();
	std::string getType();
	//std::vector<Coord*> rotateClock();
	//std::vector<Coord*> rotateCounterClock();
	//void executeClock();
	//void executeCounterClock();
};

#endif
