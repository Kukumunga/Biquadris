#include "blockj.h"
#include "coord.h"
#include <vector>
using namespace std;

BlockJ::BlockJ():Block("J", "darkgreen"){}

string BlockJ::getType(){return Block::agetType();}

vector<Coord> BlockJ::rotateClock(){
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
	//build rotate coordinates of block
	if (orientation == "up"){
		newCoords.emplace_back(Coord(lowerLeftX, lowerLeftY));
		newCoords.emplace_back(Coord(lowerLeftX, lowerLeftY - 1));
		newCoords.emplace_back(Coord(lowerLeftX, lowerLeftY - 2));
		newCoords.emplace_back(Coord(lowerLeftX + 1, lowerLeftY - 2));
	}else if (orientation == "right"){
		newCoords.emplace_back(Coord(lowerLeftX, lowerLeftY - 1));
		newCoords.emplace_back(Coord(lowerLeftX + 1, lowerLeftY - 1));
		newCoords.emplace_back(Coord(lowerLeftX + 2, lowerLeftY));
		newCoords.emplace_back(Coord(lowerLeftX + 2, lowerLeftY - 1));
	}else if (orientation == "down"){
		newCoords.emplace_back(Coord(lowerLeftX, lowerLeftY));
		newCoords.emplace_back(Coord(lowerLeftX + 1, lowerLeftY));
		newCoords.emplace_back(Coord(lowerLeftX + 1, lowerLeftY - 1));
		newCoords.emplace_back(Coord(lowerLeftX + 1, lowerLeftY - 2));
	}else{//left
		newCoords.emplace_back(Coord(lowerLeftX, lowerLeftY));
		newCoords.emplace_back(Coord(lowerLeftX, lowerLeftY - 1));
		newCoords.emplace_back(Coord(lowerLeftX + 1, lowerLeftY));
		newCoords.emplace_back(Coord(lowerLeftX + 2, lowerLeftY));
	}
	return newCoords;
}

void BlockJ::executeClock(){
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
	//build rotate coordinates of block
	if (orientation == "up"){
		components[0].setCoord(lowerLeftX, lowerLeftY);
		components[1].setCoord(lowerLeftX, lowerLeftY - 1);
		components[2].setCoord(lowerLeftX, lowerLeftY - 2);
		components[3].setCoord(lowerLeftX + 1, lowerLeftY - 2);
		orientation = "right";
	}else if (orientation == "right"){
		components[0].setCoord(lowerLeftX, lowerLeftY - 1);
		components[1].setCoord(lowerLeftX + 1, lowerLeftY - 1);
		components[2].setCoord(lowerLeftX + 2, lowerLeftY);
		components[3].setCoord(lowerLeftX + 2, lowerLeftY - 1);
		orientation = "down";
	}else if (orientation == "down"){
		components[0].setCoord(lowerLeftX, lowerLeftY);
		components[1].setCoord(lowerLeftX + 1, lowerLeftY);
		components[2].setCoord(lowerLeftX + 1, lowerLeftY - 1);
		components[3].setCoord(lowerLeftX + 1, lowerLeftY - 2);
		orientation = "left";
	}else{
		components[0].setCoord(lowerLeftX, lowerLeftY);
		components[1].setCoord(lowerLeftX, lowerLeftY - 1);
		components[2].setCoord(lowerLeftX + 1, lowerLeftY);
		components[3].setCoord(lowerLeftX + 2, lowerLeftY);
		orientation = "up";
	}
}

vector<Coord> BlockJ::rotateCounterClock(){
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
	//build rotate coordinates of block
	if (orientation == "up"){
		newCoords.emplace_back(Coord(lowerLeftX, lowerLeftY));
		newCoords.emplace_back(Coord(lowerLeftX + 1, lowerLeftY));
		newCoords.emplace_back(Coord(lowerLeftX + 1, lowerLeftY - 1));
		newCoords.emplace_back(Coord(lowerLeftX + 1, lowerLeftY - 2));
	}else if (orientation == "right"){
		newCoords.emplace_back(Coord(lowerLeftX, lowerLeftY));
		newCoords.emplace_back(Coord(lowerLeftX, lowerLeftY - 1));
		newCoords.emplace_back(Coord(lowerLeftX + 1, lowerLeftY));
		newCoords.emplace_back(Coord(lowerLeftX + 2, lowerLeftY));
	}else if (orientation == "down"){
		newCoords.emplace_back(Coord(lowerLeftX, lowerLeftY));
		newCoords.emplace_back(Coord(lowerLeftX, lowerLeftY - 1));
		newCoords.emplace_back(Coord(lowerLeftX, lowerLeftY - 2));
		newCoords.emplace_back(Coord(lowerLeftX + 1, lowerLeftY - 2));
	}else{
		newCoords.emplace_back(Coord(lowerLeftX, lowerLeftY - 1));
		newCoords.emplace_back(Coord(lowerLeftX + 1, lowerLeftY - 1));
		newCoords.emplace_back(Coord(lowerLeftX + 2, lowerLeftY));
		newCoords.emplace_back(Coord(lowerLeftX + 2, lowerLeftY - 1));
	}
	return newCoords;
}

void BlockJ::executeCounterClock(){
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
	//build rotate coordinates of block
	if (orientation == "up"){
		components[0].setCoord(lowerLeftX, lowerLeftY);
		components[1].setCoord(lowerLeftX + 1, lowerLeftY);
		components[2].setCoord(lowerLeftX + 1, lowerLeftY - 1);
		components[3].setCoord(lowerLeftX + 1, lowerLeftY - 2);
		orientation = "left";
	}else if (orientation == "right"){
		components[0].setCoord(lowerLeftX, lowerLeftY);
		components[1].setCoord(lowerLeftX, lowerLeftY - 1);
		components[2].setCoord(lowerLeftX + 1, lowerLeftY);
		components[3].setCoord(lowerLeftX + 2, lowerLeftY);
		orientation = "up";
	}else if (orientation == "down"){
		components[0].setCoord(lowerLeftX, lowerLeftY);
		components[1].setCoord(lowerLeftX, lowerLeftY - 1);
		components[2].setCoord(lowerLeftX, lowerLeftY - 2);
		components[3].setCoord(lowerLeftX + 1, lowerLeftY - 2);
		orientation = "right";
	}else{
		components[0].setCoord(lowerLeftX, lowerLeftY - 1);
		components[1].setCoord(lowerLeftX + 1, lowerLeftY - 1);
		components[2].setCoord(lowerLeftX + 2, lowerLeftY);
		components[3].setCoord(lowerLeftX + 2, lowerLeftY - 1);
		orientation = "down";
	}
}



