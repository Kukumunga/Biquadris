#include "level.h"
#include "coord.h"
#include "grid.h"
#include <vector>
Level::~Level(){}

void Level::moveRight(Grid *g){
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
                }
        }
}

void Level::moveLeft(Grid *g){
        //call Block's calcLeft function which returns coordinates
       std:: vector<Coord> potentialLocation = g->getCurrentBlock()->calcLeft();
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
}

void Level::dropBlock(Grid *g){
        while(moveDown(g)){}
}
