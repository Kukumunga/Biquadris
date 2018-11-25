#ifndef __LEVEL0__
#define __LEVEL0__
#include "level.h"
#include <string>

class Grid;
class Level0 : public Level {
	std::string filename;
public:
	Level0(std::string filename);
	void createBlock(Grid *);
	int getLevel();

	void moveRight(Grid *) override;
	void moveLeft(Grid *) override;
	bool moveDown(Grid *) override;
	void dropBlock(Grid *) override;			     
	void rotateBlockClock(Grid *) override;
	void rotateBlockCounterClock(Grid *) override;

};

#endif
