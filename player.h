
#ifndef __PLAYER__H
#define __PLAYER__H

#include "grid.h"
#include "level.h"
#include "level0.h"
#include <memory>
#include "level1.h"
#include "level2.h"
#include "level3.h"
#include "level4.h"
#include <string>
class Player{
	Xwindow *w;
	
	int displayConst;
	std::unique_ptr<Grid> g; 
	std::unique_ptr<Level> l;
	int score = 0;
	bool turn = false;
	int playerId;
	int seed = 1;
	std::string f; //file name
public:
	void initDisplay();

	int getScore() const;
	int getLevel() const;
	Player(int,int,std::string,int,Xwindow*,int);
	void printRow(int) const;
	bool moveBlockLeft(int);
	bool moveBlockRight(int);
	void moveBlockDown(int);
	void rotateBlockClockwise(int);
	void rotateBlockCounterClockwise(int);
	void dropBlock();
	void printNextBlock(int) const;
	void myTurn();
	void notMyTurn();
	void levelUp(int);
	void levelDown(int);
	bool canSpecialAction();
	void Blind();
	void Heavy();
	void Force(std::string);
	void setClear();
	int getLevel();
	void noRandom(std::string);
	void Random();
	void  nextBlock();
	void Reset();
	void createNext();
	void setLevel(int);
	void clearRows();
	void calcScore();
	void unBlind();
	void UpdateGrid();
	void unHeavy();
	void startingLevel(int);
};

#endif
