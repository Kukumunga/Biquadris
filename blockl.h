#ifndef __BLOCK__L
#define __BLOCK__L
#include <vector>
#include <string>
#include "block.h"
// 
class Coord;
class BlockL : public Block {
public:
	BlockL();
	std::string getType();
	std::vector<Coord> rotateClock();
	//std::vector<Coord*> rotateCounterClock();
	//void executeClock();
	//void executeCounterClock();
};

#endif
