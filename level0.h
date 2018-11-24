#ifndef __LEVEL0__
#define __LEVEL0__
#include "level.h"
#include <string>
<<<<<<< HEAD

=======
>>>>>>> 5c5e161c873ce729fe889fa14d761a12548f9b64
class Grid;
class Level0 : public Level {
	std::string filename;
public:
	Level0(std::string filename);
	void createBlock(Grid *);
	int getLevel();
};

#endif
