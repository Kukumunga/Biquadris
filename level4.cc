#include "level4.h"
#include "grid.h"
#include "coord.h"
#include <cstdlib>
#include <ctime>
#include <cmath>
Level4::Level4():Level(){}

int Level4::getLevel(){return 4;}

void Level4::createBlock(Grid *g){
        std::string blocks[9] = {"s","s","z","z","j","i","l","o","t"};
        srand(time(0));
        int r = rand() % 9;
        g->createBlock(blocks[r],4);

}

void Level4::resetCounter(){
	blockCounter = 0;
}

void Level4::dropBlock(Grid *g){
	dropBlock(g);
	blockCounter++;
	if (blockCounter == 5){
		//call grid method to drop a block down the center
		blockCounter = 0;
	}
}

int Level4::calculateScore(Grid *g){
        int c = g->numCleared();
	if (c > 0){
		return pow(4 + c,2);
	}else{
		return 0;
	}
}

