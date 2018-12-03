#include "blocki.h"
#include "coord.h"
#include <vector>
#include <string>
using namespace std;

BlockI::BlockI():Block("I", "blue"){}

string BlockI::getType(){
	return Block::agetType();
}

vector<Coord> BlockI::rotateClock(){
	vector<Coord> newCoords;
	int lowerLeftX = 13, lowerLeftY = -1, candidateX, candidateY;
	//get bottom left coord of block square
	for (int comp = 0; comp < 4; comp++){
		candidateX = components[comp].getX();
		candidateY = components[comp].getY();
		if (candidateX < lowerLeftX){
			lowerLeftX = candidateX;
		}
		if (candidateY > lowerLeftY){
			lowerLeftY = candidateY;
		}
	}
	//build rotated coordinates of block
	if (orientation == "left" || orientation == "right"){
		newCoords.emplace_back(Coord(lowerLeftX, lowerLeftY));
		newCoords.emplace_back(Coord(lowerLeftX, lowerLeftY - 1));
		newCoords.emplace_back(Coord(lowerLeftX, lowerLeftY - 2));
		newCoords.emplace_back(Coord(lowerLeftX, lowerLeftY - 3));
	}else{
		newCoords.emplace_back(Coord(lowerLeftX, lowerLeftY));
		newCoords.emplace_back(Coord(lowerLeftX + 1, lowerLeftY));
		newCoords.emplace_back(Coord(lowerLeftX + 2, lowerLeftY));
		newCoords.emplace_back(Coord(lowerLeftX + 3, lowerLeftY));
	}
	return newCoords;
}

vector<Coord> BlockI::rotateCounterClock(){
	return rotateClock();
}

void BlockI::executeClock(){
	int lowerLeftX = 13, lowerLeftY = -1, candidateX, candidateY;
	//get bottom left coord of block square
	for (int comp = 0; comp < 4; comp++){
		candidateX = components[comp].getX();
		candidateY = components[comp].getY();
		if (candidateX < lowerLeftX){
			lowerLeftX = candidateX;
		}
		if (candidateY > lowerLeftY){
			lowerLeftY = candidateY;
		}
	}
	//build rotated coordinates of block
	if (orientation == "up" || orientation == "down"){
		components[0].setCoord(lowerLeftX, lowerLeftY);
		components[1].setCoord(lowerLeftX, lowerLeftY - 1);
		components[2].setCoord(lowerLeftX, lowerLeftY - 2);
		components[3].setCoord(lowerLeftX, lowerLeftY - 3);
	}else{	
		components[0].setCoord(lowerLeftX, lowerLeftY);
		components[1].setCoord(lowerLeftX + 1, lowerLeftY);
		components[2].setCoord(lowerLeftX + 2, lowerLeftY);
		components[3].setCoord(lowerLeftX + 3, lowerLeftY);
	}
	if (orientation == "up"){orientation = "right";}
	else if (orientation == "right"){orientation = "down";}
	else if (orientation == "down"){orientation = "left";}
	else if (orientation == "left"){orientation = "up";}
}

void BlockI::executeCounterClock(){
	executeClock();
}
