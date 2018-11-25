
#ifndef __PLAYER__H
#define __PLAYER__H

#include "grid.h"
#include "level.h"
#include "level0.h"

class Player{
	Grid g; 
	Level0 l = Level0{"hello"};
	int score = 0;
	bool turn = false;
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
	void printNextBlock(int);
	void myTurn();
	void notMyTurn();
};

#endif
