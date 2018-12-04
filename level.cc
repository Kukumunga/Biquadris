#include "level.h"
#include "coord.h"
#include "grid.h"
#include <vector>
Level::~Level(){}

Level::Level(){}

bool Level::moveRight(Grid *g, int multiplier, bool moved){
	int heavyDrops = 0;
	if (multiplier > 0){ 
        	//call Block's calcRight function which returns coordinates
        	std:: vector<Coord> potentialLocation = g->getCurrentBlock()->calcRight();
        	for (int comp = 0; comp < 4; comp++){
                	if (potentialLocation[comp].getX() > 10 ||
                                	(g->isFilled(potentialLocation[comp].getX(),potentialLocation[comp].getY())
                                	&& !g->getCurrentBlock()->isComponent(potentialLocation[comp]))){
                        	break; //do not move right because the block is... blocked
                	}
                	if (comp == 3){ //if all the components of the block can move right                     
                        	g->turnOff();
                	        g->getCurrentBlock()->executeRight();
				return moveRight(g, multiplier - 1, true);
               		}
        	}
	}
	if (moved){
		if (g->getCurLevel() >= 3){ //if block was created in level 3 or 4
			moveDown(g, 1);
		}
	
		if (g->getHeavy()){
			for (int drops = 0; drops < 2; drops++){ //count the amount of times it can drop
				if(moveDown(g, 1)){
					++heavyDrops;
				}
			}
			std::cout << heavyDrops << std::endl;
			if(heavyDrops < 2){ //if the block cannot drop twice due to Heavy effect
				return true;
			}
		}
	}
	return false;
}

bool Level::moveLeft(Grid *g, int multiplier, bool moved){
	int heavyDrops = 0;
	if (multiplier > 0){
        	//call Block's calcLeft function which returns coordinates
        	std:: vector<Coord> potentialLocation = g->getCurrentBlock()->calcLeft();
        	for (int comp = 0; comp < 4; comp++){
                	if (potentialLocation[comp].getX() < 0 || //out of bounds
                                	(g->isFilled(potentialLocation[comp].getX(),potentialLocation[comp].getY()) //not filled already
                                	&& !g->getCurrentBlock()->isComponent(potentialLocation[comp]))){ //not filled by block's own component

                        	break;; //do not move left because the block is... blocked
                	}
                	if (comp == 3){ //if all the components of the block can move right                     
                        	g->turnOff();
                        	g->getCurrentBlock()->executeLeft();
				return moveLeft(g, multiplier - 1, true);
                	}
        	}
	}
	if (moved){
		if (g->getCurLevel() >= 3){ //if block was created in level 3 or 4
			moveDown(g, 1);
		}

		if (g->getHeavy()){
			for (int drops = 0; drops < 2; drops++){ //count the amount of times it can drop
				if(moveDown(g, 1)){++heavyDrops;}
			}
			if(heavyDrops < 2){ //if the block cannot drop twice due to Heavy effect
				return true;
			}
		}
	}
	return false;
}


bool Level::moveDown(Grid *g, int multiplier){
	if (multiplier > 0){
        	//call Block's calcDown function which returns coordinates
        	std::vector<Coord> potentialLocation = g->getCurrentBlock()->calcDown();
        	for (int comp = 0; comp < 4; comp++){
                	if (potentialLocation[comp].getY() > 17 ||
                                	(g->isFilled(potentialLocation[comp].getX(),potentialLocation[comp].getY()) 
                        	        && !g->getCurrentBlock()->isComponent(potentialLocation[comp]))){
                        
                        	return false;; //do not move down because the block is... blocked
                	}
                	if (comp == 3){ //if all the components of the block can move right                     
                        	g->turnOff(); 
                        	g->getCurrentBlock()->executeDown();
				return moveDown(g, multiplier - 1);
                	}
        	}
	}
        return true;
}

void Level::rotateBlockClock(Grid *g, int multiplier){
	if (multiplier > 0){
        	//call Block's rotateBlockClock which returns coordinates
        	std::vector<Coord> potentialLocation = g->getCurrentBlock()->rotateClock();
        	for (int comp = 0; comp < 4; comp++){
                	if (potentialLocation[comp].getY() > 17 ||
                                	(g->isFilled(potentialLocation[comp].getX(),potentialLocation[comp].getY()) 
                                	&& !g->getCurrentBlock()->isComponent(potentialLocation[comp]))){
                        
                        	break;; //do not rotate clockwise because the block is... blocked
                	}
                	if (comp == 3){ //if all the components of the block can move right                     
                        	g->turnOff(); 
                        	g->getCurrentBlock()->executeClock();
				rotateBlockClock(g, multiplier - 1);
                	}
        	}
	}
	if (g->getCurLevel() >= 3){ //if block was created in level 3 or 4
		moveDown(g, 1);
	}
}

void Level::rotateBlockCounterClock(Grid *g, int multiplier){
	if (multiplier > 0){
        	//call Block's rotateBlockCounterClock which returns coordinates
        	std::vector<Coord> potentialLocation = g->getCurrentBlock()->rotateCounterClock();
        	for (int comp = 0; comp < 4; comp++){
                	if (potentialLocation[comp].getY() > 17 ||
                                	(g->isFilled(potentialLocation[comp].getX(),potentialLocation[comp].getY()) 
                                	&& !g->getCurrentBlock()->isComponent(potentialLocation[comp]))){
                        
                        	break;; //do not rotate counter clockwise because the block is... blocked
                	}
                	if (comp == 3){ //if all the components of the block can move right                     
                        	g->turnOff(); 
                        	g->getCurrentBlock()->executeCounterClock();
				rotateBlockCounterClock(g, multiplier - 1);
                	}
        	}
	}
	if (g->getCurLevel() >= 3){ //if block was created in level 3 or 4
		moveDown(g, 1);
	}	
}

void Level::dropBlock(Grid *g){
        while(moveDown(g, 1)){}
}
