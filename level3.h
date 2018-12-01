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
public:
	Level3();
        void createBlock(Grid *);
        int getLevel();
        int calculateScore(Grid*) override;
};

#endif
