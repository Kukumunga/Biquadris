#include "blocki.h"
#include "coord.h"
#include <vector>
using namespace std;

BlockI::BlockI():Block("I", "green"){}

string BlockI::getType(){
	return Block::agetType();
}

vector<Coord> BlockI::rotateClock(){
	vector<Coord> newCoords;
	int lowerLeftX, lowerLeftY;
	return newCoords;
}
