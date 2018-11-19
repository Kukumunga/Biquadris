#ifndef __CELL__H
#define __CELL__H

#include <iostream>

class Cell {

private:
	// std::string colour;
	int signal;
	char block = 'L';
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
	char getBlockChar();
	void setBlockChar(char);
	Cell(int,int);
	void addLeftNeighbour(Cell *);
	void addRightNeighbour(Cell *);
	void alertNeighbours();
	bool clanClearRow();
	void setStatus(bool);
	bool getStatus();

};


std::ostream& operator<<(std::ostream &out, Cell &c);

#endif