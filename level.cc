#include "level.h"
#include "coord.h"
#include "grid.h"
#include <vector>
Level::~Level(){}

Level::Level(){}

bool Level::moveRight(Grid *g){
	int heavyDrops;//counter for amount of drops 
        //call Block's calcRight function which returns coordinates
        std:: vector<Coord> potentialLocation = g->getCurrentBlock()->calcRight();
        for (int comp = 0; comp < 4; comp++){
                if (potentialLocation[comp].getX() > 10 ||
                                (g->isFilled(potentialLocation[comp].getX(),potentialLocation[comp].getY())
                                && !g->getCurrentBlock()->isComponent(potentialLocation[comp]))){
                        return false; //do not move right because the block is... blocked
                }
                if (comp == 3){ //if all the components of the block can move right                     
                        g->turnOff();
                        g->getCurrentBlock()->executeRight();
                }
        }
	
	if (g->getCurLevel() >= 3){ //if block was created in level 3 or 4
		moveDown(g);
	}
	
	if (g->getHeavy()){
		for (int drops = 0; drops < 2; drops++){ //count the amount of times it can drop
			if(moveDown(g)){++heavyDrops;}
		}
		if(heavyDrops < 2){ //if the block cannot drop twice due to Heavy effect
			return true;
		}
	}
	return false;
}

bool Level::moveLeft(Grid *g){
	int heavyDrops;
        //call Block's calcLeft function which returns coordinates
       std:: vector<Coord> potentialLocation = g->getCurrentBlock()->calcLeft();
        for (int comp = 0; comp < 4; comp++){
                if (potentialLocation[comp].getX() < 0 || //out of bounds
                                (g->isFilled(potentialLocation[comp].getX(),potentialLocation[comp].getY()) //not filled already
                                && !g->getCurrentBlock()->isComponent(potentialLocation[comp]))){ //not filled by block's own component

                        return false;; //do not move left because the block is... blocked
                }
                if (comp == 3){ //if all the components of the block can move right                     
                        g->turnOff();
                        g->getCurrentBlock()->executeLeft();
                }
        }

	if (g->getCurLevel() >= 3){ //if block was created in level 3 or 4
		moveDown(g);
	}

	if (g->getHeavy()){
		for (int drops = 0; drops < 2; drops++){ //count the amount of times it can drop
			if(moveDown(g)){++heavyDrops;}
		}
		if(heavyDrops < 2){ //if the block cannot drop twice due to Heavy effect
			return true;
		}
	}
	return false;
}


bool Level::moveDown(Grid *g){
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
                }
        }

	if (g->getCurLevel() >= 3){ //if block was created in level 3 or 4
		moveDown(g);
	}

        return true;
}

void Level::rotateBlockClock(Grid *g){
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
                }
        }

	if (g->getCurLevel() >= 3){ //if block was created in level 3 or 4
		moveDown(g);
	}
}

void Level::rotateBlockCounterClock(Grid *g){
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
                }
        }

	if (g->getCurLevel() >= 3){ //if block was created in level 3 or 4
		moveDown(g);
	}	
}

void Level::dropBlock(Grid *g){
        while(moveDown(g)){}
}
