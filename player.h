
#ifndef __PLAYER__H
#define __PLAYER__H

#include "grid.h"
#include "level.h"
#include "level0.h"
#include <memory>
#include "level1.h"
#include "level2.h"
class Player{
	std::unique_ptr<Grid> g; 
	std::unique_ptr<Level> l;// {new Level0("sequence1")};
	int score = 0;
	bool turn = false;
	int playerId = 0;
public:
	int getScore() const;
	int getLevel() const;
	Player(int);
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
	void levelUp();
	void levelDown();
	bool canSpecialAction();
	void Blind();
	void Heavy();
//	void Force(std::string);
};

#endif
