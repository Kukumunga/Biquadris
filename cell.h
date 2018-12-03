#ifndef __CELL__H
#define __CELL__H

#include "window.h"
#include <iostream>
#include "coord.h"
#include <string>
class Cell {

private:
	Xwindow *w; //pointer to the window that this cell belongs to
	int displayConst;

	const int width = 20; //also the height, for the block
	std::string colour = "white"; //the colour of the block
	
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
	void draw(); //updates the colour of the cell
	void undraw(); //makes the cell white

	std::string getBlockChar();
	void setBlockColour(std::string);
	void setBlockChar(std::string);
	Cell(int,int,Xwindow*,int);
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
