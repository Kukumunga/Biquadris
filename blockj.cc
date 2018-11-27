#include "blockj.h"
#include "coord.h"
#include <vector>
using namespace std;

BlockJ::BlockJ():Block("J", "red"){}

string BlockJ::getType(){return Block::agetType();}

vector<Coord> BlockJ::rotateClock(){
        


}
vector<Coord> BlockJ::rotateCounterClock(){
	        return rotateClock();
}
void BlockJ::executeClock(){
}
void BlockJ::executeCounterClock(){
}

