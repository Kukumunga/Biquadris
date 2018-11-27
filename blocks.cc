#include "blocks.h"
#include "coord.h"
#include <vector>
using namespace std;

BlockS::BlockS():Block("S", "yellow"){}
string BlockS::getType(){return Block::agetType();}

vector<Coord> BlockS::rotateClock(){
        vector<Coord> newCoords;
        int lowerLeftX, lowerLeftY;
        return newCoords;
}
vector<Coord> BlockS::rotateCounterClock(){
	        return rotateClock();
}
void BlockS::executeClock(){
}
void BlockS::executeCounterClock(){
}

