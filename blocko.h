#ifndef __BLOCK__O
#define __BLOCK__O
#include <vector>
#include <string>
#include "block.h"

class Coord;
class BlockO : public Block {
public:
	BlockO();
	std::string getType();
	//std::vector<Coord*> rotateClock();
	//std::vector<Coord*> rotateCounterClock();
	//void executeClock();
	//void executeCounterClock();
};

#endif
