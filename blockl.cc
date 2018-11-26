#include "blockl.h"
#include <vector>
#include "coord.h"
using namespace std;

BlockL::BlockL():Block("L", "orange"){}
string BlockL::getType(){return Block::agetType();}

vector<Coord> BlockL::rotateClock(){
        vector<Coord> newCoords;
        int lowerLeftX, lowerLeftY;
        return newCoords;
}

