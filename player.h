
#ifndef __PLAYER__H
#define __PLAYER__H

#include "grid.h"
#include "level.h"
#include "level0.h"
#include <memory>

class Player{
	std::unique_ptr<Grid> g; 
	Level0 l = Level0{"sequence1"};
	int score = 0;
	bool turn = false;
public:
	int getScore() const;
	int getLevel() const;
	Player();
	void printRow(int) const;
	void moveBlockLeft();
	void moveBlockRight();
	void moveBlockDown();
	void rotateBlockClockwise();
	void rotateBlockCounterClockwise();
	void dropBlock();
	void printNextBlock(int) const;
	void myTurn();
	void notMyTurn();
};

#endif
