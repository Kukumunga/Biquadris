
#ifndef __PLAYER__H
#define __PLAYER__H

#include "grid.h"

class Player{
	Grid g; 
	Level l;
	int score = 0;
	// Block *nextBlock;
public:
	int getScore();
	int getLevel();
	Player();
	void printRow(int);
	void moveBlockLeft();
	void moveBlockRight();
	void moveBlockDown();
	void dropBlock();
};






#endif