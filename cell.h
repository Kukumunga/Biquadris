#ifndef __CELL__H
#define __CELL__H

#include <iostream>

class Cell {

private:
	// std::string colour;
	char block = 'L';
	Coord c;
	bool isActive = false; // if nothing in cell then inactive
public:
	char getBlockChar();
	Cell(int,int);
};


std::ostream& operator<<(std::ostream &out, Cell &c);

#endif