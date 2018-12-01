#include "level2.h"
#include "grid.h"
#include "coord.h"
#include <cstdlib>
#include <ctime>
#include <cmath>
Level2::Level2():Level(){}

int Level2::getLevel(){return 2;}

void Level2::noRandom(std::string){
}


void Level2::createBlock(Grid *g){
        std::string blocks[7] = {"s","z","j","i","l","o","t"};
        srand(time(0));
        int r = rand() % 7;
        g->createBlock(blocks[r],2);

}
int Level2::calculateScore(Grid *g){
        int c = g->numCleared();
	if (c > 0){
		return pow(2 + c,2);
	}else{
		return 0;
	}
}
