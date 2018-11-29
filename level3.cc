#include "level3.h"
#include "grid.h"
#include "coord.h"
#include <cstdlib>
#include <ctime>
#include <cmath>
int Level3::getLevel(){return 3;}

void Level3::createBlock(Grid *g){
        std::string blocks[9] = {"s","s","z","z","j","i","l","o","t"};
        srand(time(0));
        int r = rand() % 7;
        g->createBlock(blocks[r],2);

}
int Level3::calculateScore(Grid *g){
        return pow((3 + g->numCleared()),2);
}
