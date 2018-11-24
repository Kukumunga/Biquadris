#ifndef __GRID__H
#define __GRID__H

#include <vector>
#include "cell.h"

const int MID = 5;

class Grid{
	std::vector<std::vector<Cell>> theGrid;
	Block *currentBlock;
	Block *nextBlock;
	std::vector <Block> blocksInGrid;
	bool isHeavy;
	void clearRow(int);

public:
	Grid();
	void printRow(int);
	bool getHeavy();
	void setCurrentBlock(Block *);
	void setNextBlock(Block *);
	void addToCurrent();
	void clearFullRows();
};


#endif
