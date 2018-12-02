#ifndef __LEVEL1__
#define __LEVEL1__
#include "level.h"
#include <string>
#include <vector>
#include <iostream>
class Grid;
class Level1 : public Level {
	std::vector<std::string> blocks;
	std::vector<std::string>::iterator it;
public:
	Level1();
	void createBlock(Grid *);
	void resetCounter() override{};
	int getLevel();
	int calculateScore(Grid*) override;
	void noRandom(std::string) override;
};

#endif
