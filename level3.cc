#include "level3.h"
#include "grid.h"
#include "coord.h"
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream>
#include <iostream>
Level3::Level3():Level(){}

int Level3::getLevel(){return 3;}

void Level3::createBlock(Grid *g){
       	if (!random){
		std::string block = *it;

        	if (block == "I"){g->createBlock("i", 3);}
        	else if (block == "L"){g->createBlock("l", 3);}
        	else if (block == "J"){g->createBlock("j", 3);}
        	else if (block == "S"){g->createBlock("s", 3);}
        	else if (block == "Z"){g->createBlock("z", 3);}
        	else if (block == "O"){g->createBlock("o", 3);}
        	else if (block == "T"){g->createBlock("t", 3);}
	
        	++it;
        	if (it == blocks.end()){ it = blocks.begin();}
	}else{
		std::string blocks[9] = {"s","s","z","z","j","i","l","o","t"};
        	srand(time(0));
        	int r = rand() % 9;
        	g->createBlock(blocks[r],3);
	}
}

void Level3::Random(){
	random = true;
}

void Level3::noRandom(std::string filename){
	random = false;
	std::ifstream f{filename};
       	std::string s;
        while (f >> s){
                blocks.emplace_back(s);
        }
        it = blocks.begin();
        f.close();
}

int Level3::calculateScore(Grid *g){
        int c = g->numCleared();
	if (c > 0){
		return pow(3 + c,2);
	}else{
		return 0;
	}
}

