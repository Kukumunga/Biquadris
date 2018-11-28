#ifndef __GRID__H
#define __GRID__H

#include <vector>
#include <memory>
#include "cell.h"
#include "block.h"
const int MID = 5;

class Grid{
	bool containsNext = false;
	std::vector<std::vector<Cell>> theGrid;
	Block *currentBlock;
	Block *nextBlock;
	std::vector <std::unique_ptr<Block>> blocksInGrid;
	bool isHeavy;
	void clearRow(int);
	int numClear = 0;

public:
	Grid();
	//Grid(const Grid &g) = delete;
	/*
	Grid(const Grid& g):blocksInGrid{std::move(g.blocksInGrid)}{
		std::cout << "HERE" << std::endl;	
	}
	Grid* operator=(const Grid&g){
		blocksInGrid = std::move(g.blocksInGrid);
		
		std::cout << "HERE2" << std::endl;
		return this;
	}
	*/
	//~Grid();
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
	void next();
	void setFilledStatus(int,int);
	void turnOn(int,int);
	void turnAllOff();
	void Blind();
};


#endif
