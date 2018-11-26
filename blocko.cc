#include "blocko.h"
#include <vector>
#include "coord.h"
using namespace std;

BlockO::BlockO():Block("O", "blue"){}
string BlockO::getType(){return Block::agetType();}

vector<Coord> BlockO::rotateClock(){
        vector<Coord> newCoords;
        int lowerLeftX, lowerLeftY;
        return newCoords;
}

