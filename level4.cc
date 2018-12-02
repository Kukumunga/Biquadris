#include "level4.h"
#include "grid.h"
#include "coord.h"
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream>
#include <iostream>
Level4::Level4():Level(){}

int Level4::getLevel(){return 4;}

void Level4::createBlock(Grid *g){
        if (!random){
                std::string block = *it;

                if (block == "I"){g->createBlock("i", 4);}
                else if (block == "L"){g->createBlock("l", 4);}
                else if (block == "J"){g->createBlock("j", 4);}
                else if (block == "S"){g->createBlock("s", 4);}
                else if (block == "Z"){g->createBlock("z", 4);}
                else if (block == "O"){g->createBlock("o", 4);}
                else if (block == "T"){g->createBlock("t", 4);}

                ++it;
                if (it == blocks.end()){ it = blocks.begin();}
        }else{
		std::string blocks[9] = {"s","s","z","z","j","i","l","o","t"};
        	srand(time(0));
        	int r = rand() % 9;
        	g->createBlock(blocks[r],4);
	}

}
void Level4::Random(){
	random = true;
}

void Level4::noRandom(std::string filename){
        random = false;
        std::ifstream f{filename};
        std::string s;
        while (f >> s){
                blocks.emplace_back(s);
        }
        it = blocks.begin();
        f.close();
}


void Level4::resetCounter(){
	blockCounter = 0;
}

void Level4::dropBlock(Grid *g){
	Level::dropBlock(g);
	blockCounter++;
	if (blockCounter == 5){
		g->dropStar();
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

