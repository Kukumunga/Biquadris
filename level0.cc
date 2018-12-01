#include "level0.h"
#include "grid.h"
#include "coord.h"
#include "blocki.h"
#include <fstream>
#include <iostream>
#include <cmath>

//include all the other block files
using namespace std;

Level0::Level0(const string &filename):Level(false){
	ifstream f{filename};
	string s;
	while (f >> s){
		blocks.emplace_back(s);
	}
	it = blocks.begin();
	f.close();
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
/*void Level0::moveRight(Grid *g){
	//call Block's calcRight function which returns coordinates
	vector<Coord> potentialLocation = g->getCurrentBlock()->calcRight();
	for (int comp = 0; comp < 4; comp++){
		if (potentialLocation[comp].getX() > 10 ||
				(g->isFilled(potentialLocation[comp].getX(),potentialLocation[comp].getY())
				&& !g->getCurrentBlock()->isComponent(potentialLocation[comp]))){
			break; //do not move right because the block is... blocked
		}
		if (comp == 3){ //if all the components of the block can move right			
			g->turnOff(); 
			g->getCurrentBlock()->executeRight();
		}
	}
}*/
/*
void Level0::moveLeft(Grid *g){
	//call Block's calcLeft function which returns coordinates
	vector<Coord> potentialLocation = g->getCurrentBlock()->calcLeft();
	for (int comp = 0; comp < 4; comp++){
		if (potentialLocation[comp].getX() < 0 || //out of bounds
				(g->isFilled(potentialLocation[comp].getX(),potentialLocation[comp].getY()) //not filled already
				&& !g->getCurrentBlock()->isComponent(potentialLocation[comp]))){ //not filled by block's own component

			break; //do not move left because the block is... blocked
		}
		if (comp == 3){ //if all the components of the block can move right			
			g->turnOff(); 
			g->getCurrentBlock()->executeLeft();
		}
	}
}*/

/* bool Level0::moveDown(Grid *g){
	//call Block's calcDown function which returns coordinates
	vector<Coord> potentialLocation = g->getCurrentBlock()->calcDown();
	for (int comp = 0; comp < 4; comp++){
		if (potentialLocation[comp].getY() > 17 ||
				(g->isFilled(potentialLocation[comp].getX(),potentialLocation[comp].getY()) 
				&& !g->getCurrentBlock()->isComponent(potentialLocation[comp]))){
			
			return false;; //do not move down because the block is... blocked
		}
		if (comp == 3){ //if all the components of the block can move right			
			g->turnOff(); 
			g->getCurrentBlock()->executeDown();
		}
	}
	return true;
}*/
/*
void Level0::dropBlock(Grid *g){
	while(moveDown(g)){}
}
*/
/*void Level0::rotateBlockClock(Grid *g){
	//call Block's rotateBlockClock which returns coordinates
	vector<Coord> potentialLocation = g->getCurrentBlock()->rotateClock();
	for (int comp = 0; comp < 4; comp++){
		if (potentialLocation[comp].getY() > 17 ||
				(g->isFilled(potentialLocation[comp].getX(),potentialLocation[comp].getY()) 
				&& !g->getCurrentBlock()->isComponent(potentialLocation[comp]))){
			
			break;; //do not rotate clockwise because the block is... blocked
		}
		if (comp == 3){ //if all the components of the block can move right			
			g->turnOff(); 
			g->getCurrentBlock()->executeClock();
		}
	}
}*/
/*void Level0::rotateBlockCounterClock(Grid *g){
	//call Block's rotateBlockCounterClock which returns coordinates
	vector<Coord> potentialLocation = g->getCurrentBlock()->rotateCounterClock();
	for (int comp = 0; comp < 4; comp++){
		if (potentialLocation[comp].getY() > 17 ||
				(g->isFilled(potentialLocation[comp].getX(),potentialLocation[comp].getY()) 
				&& !g->getCurrentBlock()->isComponent(potentialLocation[comp]))){
			
			break;; //do not rotate counter clockwise because the block is... blocked
		}
		if (comp == 3){ //if all the components of the block can move right			
			g->turnOff(); 
			g->getCurrentBlock()->executeCounterClock();
		}
	}
}
*/
