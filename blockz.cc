#include "blockz.h"
#include "coord.h"
#include <vector>
using namespace std;

BlockZ::BlockZ():Block("Z", "black"){}
string BlockZ::getType(){return Block::agetType();}

vector<Coord> BlockZ::rotateClock(){
        vector<Coord> newCoords;
        int lowerLeftX, lowerLeftY;
        return newCoords;
}
vector<Coord> BlockZ::rotateCounterClock(){
	        return rotateClock();
}
void BlockZ::executeClock(){
}
void BlockZ::executeCounterClock(){
}

