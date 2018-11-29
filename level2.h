#ifndef __LEVEL2__
#define __LEVEL2__
#include "level.h"
#include <string>
#include <vector>
#include <iostream>
class Grid;
class Level2 : public Level {
        std::vector<std::string> blocks;
        std::vector<std::string>::iterator it;
public:
        void createBlock(Grid *);
        int getLevel();
	int calculateScore(Grid *g) override;
};

#endif
