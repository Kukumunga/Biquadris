#include "blockz.h"
#include "coord.h"
#include <vector>
using namespace std;

BlockZ::BlockZ():Block("Z", "purple"){}
string BlockZ::getType(){return Block::agetType();}
vector<Coord> BlockZ::rotateClock(){
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
		newCoords.emplace_back(Coord(lowerLeftX, lowerLeftY - 1));
		newCoords.emplace_back(Coord(lowerLeftX + 1, lowerLeftY));
		newCoords.emplace_back(Coord(lowerLeftX + 1, lowerLeftY - 1));
		newCoords.emplace_back(Coord(lowerLeftX + 2, lowerLeftY));
	}else{
		newCoords.emplace_back(Coord(lowerLeftX, lowerLeftY));
		newCoords.emplace_back(Coord(lowerLeftX, lowerLeftY - 1));
		newCoords.emplace_back(Coord(lowerLeftX + 1, lowerLeftY - 1));
		newCoords.emplace_back(Coord(lowerLeftX + 1, lowerLeftY - 2));
	}
	return newCoords;
}
vector<Coord> BlockZ::rotateCounterClock(){
	return rotateClock();
}
void BlockZ::executeClock(){
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
		components[0].setCoord(lowerLeftX, lowerLeftY - 1);
		components[1].setCoord(lowerLeftX + 1, lowerLeftY);
		components[2].setCoord(lowerLeftX + 1, lowerLeftY - 1);
		components[3].setCoord(lowerLeftX + 2, lowerLeftY);
	}else{	
		components[0].setCoord(lowerLeftX, lowerLeftY);
		components[1].setCoord(lowerLeftX, lowerLeftY - 1);
		components[2].setCoord(lowerLeftX + 1, lowerLeftY - 1);
		components[3].setCoord(lowerLeftX + 1, lowerLeftY - 2);
	}
	//a counterclockwise move will make the orientation wrong...but it behaves the same
	if (orientation == "up"){orientation = "right";}
	else if (orientation == "right"){orientation = "down";}
	else if (orientation == "down"){orientation = "left";}
	else if (orientation == "left"){orientation = "up";}
}

void BlockZ::executeCounterClock(){
	executeClock();
}
