#ifndef __LEVEL4__
#define __LEVEL4__
#include "level.h"
#include <string>
#include <vector>
#include <iostream>
class Grid;
class Level4 : public Level {
	int blockCounter = 0;
        std::vector<std::string> blocks;
        std::vector<std::string>::iterator it;
	bool random = true;
public:
	Level4(int);
        void createBlock(Grid *);
        int getLevel();
        int calculateScore(Grid*) override;
	void resetCounter();
	void dropBlock(Grid *) override;
	void noRandom(std::string) override;
	void Random() override;
};

#endif
