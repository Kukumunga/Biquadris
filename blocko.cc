#include "blocko.h"
#include <vector>
#include "coord.h"
using namespace std;

BlockO::BlockO():Block("O", "cyan"){}
string BlockO::getType(){return Block::agetType();}

vector<Coord> BlockO::rotateClock(){
        vector<Coord> newCoords;
        newCoords.emplace_back(components[0]);
	newCoords.emplace_back(components[1]);
	newCoords.emplace_back(components[2]);
	newCoords.emplace_back(components[3]);
        return newCoords;
}
vector<Coord> BlockO::rotateCounterClock(){
	vector<Coord> newCoords;
        newCoords.emplace_back(components[0]);
	newCoords.emplace_back(components[1]);
	newCoords.emplace_back(components[2]);
	newCoords.emplace_back(components[3]);
	return newCoords;
}
void BlockO::executeClock(){
}
void BlockO::executeCounterClock(){
}

