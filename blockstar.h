#ifndef __BLOCK__STAR
#define __BLOCK__STAR
#include "block.h"
#include <string>

class Coord;
class BlockStar : public Block {
public:
	BlockStar();
	std::string getType();
};

#endif
