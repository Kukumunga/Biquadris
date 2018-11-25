#ifndef __CELL__H
#define __CELL__H

#include <iostream>
#include "coord.h"
#include <string>
class Cell {

private:
	// std::string colour;
	int signal = 0;
	std::string block = "L";
	Coord c;
	bool Filled = false; // false means inactive
	Cell * leftNeighbour = nullptr;
	Cell * rightNeighbour = nullptr;
	// methods
	void rightNeighbourFilled();
	void leftNeighbourFilled();
	void rightSideFilled();
	void leftSideFilled();
public:
	std::string getBlockChar();
	std::string setBlockChar(std::string);
	Cell(int,int);
	void addLeftNeighbour(Cell *);
	void addRightNeighbour(Cell *);
	void alertNeighbours();
	bool canClearRow();
	void setStatus(bool);
	bool getStatus();
	int getX();
	int getY();
};


std::ostream& operator<<(std::ostream &out, Cell &c);

#endif
