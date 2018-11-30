#include "blockt.h"
#include "coord.h"
#include <vector>
using namespace std;

BlockT::BlockT():Block("T", "red"){}
string BlockT::getType(){return Block::agetType();}
vector<Coord> BlockT::rotateClock(){
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
		newCoords.emplace_back(Coord(lowerLeftX, lowerLeftY - 1));
		newCoords.emplace_back(Coord(lowerLeftX + 1, lowerLeftY - 1));
		newCoords.emplace_back(Coord(lowerLeftX + 1, lowerLeftY - 2));
		newCoords.emplace_back(Coord(lowerLeftX + 1, lowerLeftY));
	}else if (orientation == "right"){
		newCoords.emplace_back(Coord(lowerLeftX, lowerLeftY));
		newCoords.emplace_back(Coord(lowerLeftX + 1, lowerLeftY));
		newCoords.emplace_back(Coord(lowerLeftX + 1, lowerLeftY - 1));
		newCoords.emplace_back(Coord(lowerLeftX + 2, lowerLeftY));
	}else if (orientation == "down"){
		newCoords.emplace_back(Coord(lowerLeftX, lowerLeftY));
		newCoords.emplace_back(Coord(lowerLeftX, lowerLeftY - 2));
		newCoords.emplace_back(Coord(lowerLeftX, lowerLeftY - 1));
		newCoords.emplace_back(Coord(lowerLeftX + 1, lowerLeftY - 1));
	}else{
		newCoords.emplace_back(Coord(lowerLeftX, lowerLeftY - 1));
		newCoords.emplace_back(Coord(lowerLeftX + 1, lowerLeftY));
		newCoords.emplace_back(Coord(lowerLeftX + 1, lowerLeftY - 1));
		newCoords.emplace_back(Coord(lowerLeftX + 2, lowerLeftY - 1));
	}
	return newCoords;
}

vector<Coord> BlockT::rotateCounterClock(){
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
		newCoords.emplace_back(Coord(lowerLeftX, lowerLeftY - 2));
		newCoords.emplace_back(Coord(lowerLeftX, lowerLeftY - 1));
		newCoords.emplace_back(Coord(lowerLeftX + 1, lowerLeftY - 1));
	}else if (orientation == "right"){
		newCoords.emplace_back(Coord(lowerLeftX, lowerLeftY - 1));
		newCoords.emplace_back(Coord(lowerLeftX + 1, lowerLeftY));
		newCoords.emplace_back(Coord(lowerLeftX + 1, lowerLeftY - 1));
		newCoords.emplace_back(Coord(lowerLeftX + 2, lowerLeftY - 1));
	}else if (orientation == "down"){
		newCoords.emplace_back(Coord(lowerLeftX, lowerLeftY - 1));
		newCoords.emplace_back(Coord(lowerLeftX + 1, lowerLeftY - 1));
		newCoords.emplace_back(Coord(lowerLeftX + 1, lowerLeftY - 2));
		newCoords.emplace_back(Coord(lowerLeftX + 1, lowerLeftY));
	}else{
		newCoords.emplace_back(Coord(lowerLeftX, lowerLeftY));
		newCoords.emplace_back(Coord(lowerLeftX + 1, lowerLeftY));
		newCoords.emplace_back(Coord(lowerLeftX + 1, lowerLeftY - 1));
		newCoords.emplace_back(Coord(lowerLeftX + 2, lowerLeftY - 1));
	}
	return newCoords;
}
void BlockT::executeCounterClock(){
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
		components[1].setCoord(lowerLeftX, lowerLeftY - 2);
		components[2].setCoord(lowerLeftX, lowerLeftY - 1);
		components[3].setCoord(lowerLeftX + 1, lowerLeftY - 1);
		orientation = "left";
	}else if (orientation == "right"){
		components[0].setCoord(lowerLeftX, lowerLeftY - 1);
		components[1].setCoord(lowerLeftX + 1, lowerLeftY);
		components[2].setCoord(lowerLeftX + 1, lowerLeftY - 1);
		components[3].setCoord(lowerLeftX + 2, lowerLeftY - 1);
		orientation = "up";
	}else if (orientation == "down"){
		components[0].setCoord(lowerLeftX, lowerLeftY - 1);
		components[1].setCoord(lowerLeftX + 1, lowerLeftY - 1);
		components[2].setCoord(lowerLeftX + 1, lowerLeftY - 2);
		components[3].setCoord(lowerLeftX + 1, lowerLeftY);
		orientation = "right";
	}else{
		components[0].setCoord(lowerLeftX, lowerLeftY);
		components[1].setCoord(lowerLeftX + 1, lowerLeftY);
		components[2].setCoord(lowerLeftX + 1, lowerLeftY - 1);
		components[3].setCoord(lowerLeftX + 2, lowerLeftY - 1);
		orientation = "down";
	}
}
void BlockT::executeClock(){
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
		components[0].setCoord(lowerLeftX, lowerLeftY - 1);
		components[1].setCoord(lowerLeftX + 1, lowerLeftY - 1);
		components[2].setCoord(lowerLeftX + 1, lowerLeftY - 2);
		components[3].setCoord(lowerLeftX + 1, lowerLeftY);
		orientation = "right";
	}else if (orientation == "right"){
		components[0].setCoord(lowerLeftX, lowerLeftY);
		components[1].setCoord(lowerLeftX + 1, lowerLeftY);
		components[2].setCoord(lowerLeftX + 1, lowerLeftY - 1);
		components[3].setCoord(lowerLeftX + 2, lowerLeftY);
		orientation = "down";
	}else if (orientation == "down"){
		components[0].setCoord(lowerLeftX, lowerLeftY);
		components[1].setCoord(lowerLeftX, lowerLeftY - 2);
		components[2].setCoord(lowerLeftX, lowerLeftY - 1);
		components[3].setCoord(lowerLeftX + 1, lowerLeftY - 1);
		orientation = "left";
	}else{
		components[0].setCoord(lowerLeftX, lowerLeftY - 1);
		components[1].setCoord(lowerLeftX + 1, lowerLeftY);
		components[2].setCoord(lowerLeftX + 1, lowerLeftY - 1);
		components[3].setCoord(lowerLeftX + 2, lowerLeftY - 1);
		orientation = "up";
	}
}
