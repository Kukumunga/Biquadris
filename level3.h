#ifndef __LEVEL3__
#define __LEVEL3__
#include "level.h"
#include <string>
#include <vector>
#include <iostream>
class Grid;
class Level3 : public Level {
        std::vector<std::string> blocks;
        std::vector<std::string>::iterator it;
	bool random = true;
public:
	Level3();
        void resetCounter() override{};
	void createBlock(Grid *);
        int getLevel();
        int calculateScore(Grid*) override;
	void noRandom(std::string)override;
};

#endif
