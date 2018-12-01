#include "blockstar.h"
#include "coord.h"
#include <vector>

using namespace std;

BlockStar::BlockStar():Block("*", "brown"){}

vector<Coord> BlockStar::rotateClock(){
	vector<Coord> newCoords;
	return newCoords;
}

vector<Coord> BlockStar::rotateCounterClock(){
	vector<Coord> newCoords;
	return newCoords;
}

void BlockStar::executeClock(){}

void BlockStar::executeCounterClock(){}
