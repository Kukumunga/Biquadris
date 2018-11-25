#include "level0.h"
#include "grid.h"
#include "coord.h"
#include "blocki.h"
//include all the other block files
using namespace std;

Level0::Level0(string filename):filename{filename}{}

int Level0::getLevel(){return 0;}

void Level0::createBlock(Grid &g){
	g.createBlock("i", 0);
}

void Level0::moveRight(Grid *g){
	//call Block's calcRight function which returns coordinates
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
