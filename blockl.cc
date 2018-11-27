#include "blockl.h"
#include <vector>
#include "coord.h"
using namespace std;

BlockL::BlockL():Block("L", "orange"){}
string BlockL::getType(){return Block::agetType();}

vector<Coord> BlockL::rotateClock(){
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
		newCoords.emplace_back(Coord(lowerLeftX + 1, lowerLeftY));
	}else if (orientation == "right"){
		newCoords.emplace_back(Coord(lowerLeftX, lowerLeftY));
		newCoords.emplace_back(Coord(lowerLeftX, lowerLeftY - 1));
		newCoords.emplace_back(Coord(lowerLeftX + 1, lowerLeftY - 1));
		newCoords.emplace_back(Coord(lowerLeftX + 2, lowerLeftY - 1));
	}else if (orientation == "down"){
		newCoords.emplace_back(Coord(lowerLeftX, lowerLeftY - 2));
		newCoords.emplace_back(Coord(lowerLeftX + 1, lowerLeftY - 2));
		newCoords.emplace_back(Coord(lowerLeftX + 1, lowerLeftY - 1));
		newCoords.emplace_back(Coord(lowerLeftX + 1, lowerLeftY));
	}else{
		newCoords.emplace_back(Coord(lowerLeftX, lowerLeftY));
		newCoords.emplace_back(Coord(lowerLeftX + 1, lowerLeftY));
		newCoords.emplace_back(Coord(lowerLeftX + 2, lowerLeftY));
		newCoords.emplace_back(Coord(lowerLeftX + 2, lowerLeftY - 1));
	}
	return newCoords;
}
vector<Coord> BlockL::rotateCounterClock(){
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
		newCoords.emplace_back(Coord(lowerLeftX + 1, lowerLeftY));
	}else if (orientation == "right"){
		newCoords.emplace_back(Coord(lowerLeftX, lowerLeftY));
		newCoords.emplace_back(Coord(lowerLeftX, lowerLeftY - 1));
		newCoords.emplace_back(Coord(lowerLeftX + 1, lowerLeftY - 1));
		newCoords.emplace_back(Coord(lowerLeftX + 2, lowerLeftY - 1));
	}else if (orientation == "down"){
		newCoords.emplace_back(Coord(lowerLeftX, lowerLeftY - 2));
		newCoords.emplace_back(Coord(lowerLeftX + 1, lowerLeftY - 2));
		newCoords.emplace_back(Coord(lowerLeftX + 1, lowerLeftY - 1));
		newCoords.emplace_back(Coord(lowerLeftX + 1, lowerLeftY));
	}else{
		newCoords.emplace_back(Coord(lowerLeftX, lowerLeftY));
		newCoords.emplace_back(Coord(lowerLeftX + 1, lowerLeftY));
		newCoords.emplace_back(Coord(lowerLeftX + 2, lowerLeftY));
		newCoords.emplace_back(Coord(lowerLeftX + 2, lowerLeftY - 1));
	}
	return newCoords;
}

void BlockL::executeClock(){

}
void BlockL::executeCounterClock(){

}
