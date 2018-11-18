#ifndef __LEVEL0__
#define __LEVEL0__
#include "level.h"

class Grid;
class Level0 : public Level {
	std::string filename;
public:
	Level0(std::string filename);
	void createBlock(Grid *);
	int getLevel();
};

#endif
