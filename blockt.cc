#include "blockt.h"
#include "coord.h"
#include <vector>
using namespace std;

BlockT::BlockT():Block("T", "red"){}
string BlockT::getType(){return Block::agetType();}

vector<Coord> BlockT::rotateClock(){
        vector<Coord> newCoords;
        int lowerLeftX, lowerLeftY;
        return newCoords;
}

