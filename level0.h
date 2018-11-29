#ifndef __LEVEL0__
#define __LEVEL0__
#include "level.h"
#include <string>
#include <vector>
#include <iostream>
class Grid;
class Level0 : public Level {
	std::vector<std::string> blocks;
	std::vector<std::string>::iterator it;
public:
	//~Level0();
	Level0(const std::string &filename);
	void createBlock(Grid *);
	int getLevel();

//	void moveRight(Grid *) override;
//	void moveLeft(Grid *) override;
//	bool moveDown(Grid *) override;
//	void dropBlock(Grid *) override;			     
//	void rotateBlockClock(Grid *) override;
//	void rotateBlockCounterClock(Grid *) override;

};

#endif
