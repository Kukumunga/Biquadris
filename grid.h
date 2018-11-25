#ifndef __GRID__H
#define __GRID__H

#include <vector>
#include "cell.h"
#include "block.h"
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
	Block* getCurrentBlock();
	void setNextBlock(Block *);
	void addToCurrent();
	void clearFullRows();
	bool isFilled(int x, int y);
	void createBlock(std::string blockType,int level);
	void turnOff(int,int);
	void UpdateGrid();
	void setCurrentBlock(Block *);
	void turnOff();
	void printNextBlock(int line);
};


#endif
