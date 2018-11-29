#include "level1.h"
#include "grid.h"
#include "coord.h"
#include <cstdlib>
#include <ctime>
#include <cmath>
int Level1::getLevel(){return 1;}

void Level1::createBlock(Grid *g){
	std::string blocks[12] = {"s","z","j","j","i","i","l","l","o","o","t","t"};
	srand(time(0));
	int r = rand() % 12;
	g->createBlock(blocks[r],1);	

}

int Level1::calculateScore(Grid *g){
	return pow((1 + g->numCleared()),2);
}
