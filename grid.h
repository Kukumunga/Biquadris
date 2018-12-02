#ifndef __GRID__H
#define __GRID__H

#include <vector>
#include <memory>
#include "cell.h"
#include "block.h"

const int MID = 5;

class Grid{
	Xwindow *w; //pointer to the window (to pass to cells)

	bool containsNext = false;
	std::vector<std::vector<Cell>> theGrid;
	//std::unique_ptr<Block> currentBlock;
	std::unique_ptr<Block> nextBlock;
	std::unique_ptr<Block> tempBlock;
	Block *currentBlock;
	//Block *nextBlock;
	std::vector <std::unique_ptr<Block>> blocksInGrid;
	bool heavy = false;
	void clearRow(int);
	int numClear = 0;
	bool blind = false;

public:
	Grid(Xwindow *w);
	void dropStar();
	int getCurLevel();
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
	bool next();
	void setFilledStatus(int,int);
	void turnOn(int,int);
	void turnAllOff();
	void Blind();
	int numCleared();
	void unBlind();
	void Heavy();
	int blockScore();
	void Force(std::string,int);
	void unHeavy();
	void resetClear();
	bool validDrop();
	void Reset();
};


#endif
