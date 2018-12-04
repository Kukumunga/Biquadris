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
	Level0(const std::string &filename);
	void resetCounter() override{};
	void createBlock(Grid *);
	int getLevel();
	int calculateScore(Grid *) override;
	void noRandom(std::string)override;
	void Random() override{};
};

#endif
