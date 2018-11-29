#include "level1.h"
#include "grid.h"
#include "coord.h"
#include <cstdlib>

int Level1::getLevel(){return 1;}

void Level1::createBlock(Grid *g){
	std::string blocks[12] = {"S","Z","J","J","I","I","L","L","O","O","T","T"};
	g->createBlock("S",1);
}

