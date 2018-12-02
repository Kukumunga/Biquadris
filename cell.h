#ifndef __CELL__H
#define __CELL__H

#include <iostream>
#include "coord.h"
#include <string>
class Cell {

private:
	std::string colour; //the colour of the block
	int signal = 0;
	std::string block = "";
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
	void setBlockChar(std::string);
	Cell(int,int);
	void addLeftNeighbour(Cell *);
	void addRightNeighbour(Cell *);
	void alertNeighbours();
	bool canClearRow();
	void turnOff(); // sets filled to false
	void turnOn(); // sets filled to true
	bool getStatus();
	int getX();
	int getY();
	Coord * getCoord();
	void setFilledStatus(bool);
	void setBlind();
};


std::ostream& operator<<(std::ostream &out, Cell &c);

#endif
