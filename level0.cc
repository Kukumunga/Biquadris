#include "level0.h"
#include "grid.h"
#include "coord.h"
#include "blocki.h"
#include <fstream>
#include <iostream>
#include <cmath>

//include all the other block files
using namespace std;

Level0::Level0(const string &filename):Level(){
	ifstream f{filename};
	string s;
	while (f >> s){
		blocks.emplace_back(s);
	}
	it = blocks.begin();
	f.close();
}

void Level0::noRandom(std::string f){
}

int Level0::getLevel(){return 0;}

void Level0::createBlock(Grid *g){
	
	string block = *it;
	
	if (block == "I"){g->createBlock("i", 0);}
	else if (block == "L"){g->createBlock("l", 0);}
	else if (block == "J"){g->createBlock("j", 0);}
	else if (block == "S"){g->createBlock("s", 0);}
	else if (block == "Z"){g->createBlock("z", 0);}
	else if (block == "O"){g->createBlock("o", 0);}
	else if (block == "T"){g->createBlock("t", 0);}	

	++it;
	if (it == blocks.end()){ it = blocks.begin();}//if the iterator finishes the blocks, restart
	
}

int Level0::calculateScore(Grid *g){
	if (g->numCleared() > 0){
		return pow(0 + g->numCleared(),2);
	}else{
		return 0;
	}
}

