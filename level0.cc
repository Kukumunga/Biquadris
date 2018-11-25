#include "level0.h"
#include "grid.h"
#include "coord.h"
#include "blocki.h"

//include all the other block files
using namespace std;

Level0::Level0(string filename):filename{filename}{}

int Level0::getLevel(){return 0;}

void Level0::createBlock(Grid *g){
	g->createBlock("i", 0);
}

void Level0::moveRight(Grid *g){
	//call Block's calcRight function which returns coordinates
	vector<Coord> potentialLocation = g->getCurrentBlock()->calcRight();
	for (int comp = 0; comp < 4; comp++){
		if (g->isFilled(potentialLocation[comp].getX(),potentialLocation[comp].getY()) && !g->getCurrentBlock()->isComponent(potentialLocation[comp])){
			break; //do not move right because the block is... blocked
		}
		if (comp == 3){ //if all the components of the block can move right			
			g->turnOff(); 
			g->getCurrentBlock()->executeRight();
		}
	}
}

void Level0::moveLeft(Grid *g){
	//call Block's calcLeft function which returns coordinates
}

void Level0::moveDown(Grid *g){
	//call Block's calcDown function which returns coordinates
}

void Level0::dropBlock(Grid *g){
	//calls moveDown until it no longer can
}

void Level0::rotateBlockClock(Grid *g){
	//call Block's rotateBlockClock which returns coordinates
}
void Level0::rotateBlockCounterClock(Grid *g){
	//call Block's rotateBlockCounterClock which returns coordinates
}
