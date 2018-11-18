#ifndef __GRID__H
#define __GRID__H

#include <vector>
#include "cell.h"

class Grid{
	std::vector<std::vector<Cell>> theGrid;
	Block *currentBlock;
	Block *nextBlock;
	std::vector <Block> currentBlocks;
	bool isHeavy;
	
public:
	Grid();
	void printRow(int);
	bool getHeavy();
	void setCurrentBlock(Block *);
	void setNextBlock(Block *);
};


#endif