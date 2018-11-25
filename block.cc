#include "block.h"
using namespace std;
#include "cell.h"
#include "coord.h"

Block::~Block(){
	components.clear();
}

Block::Block(string type, string colour):type{type}, colour{colour},orientation{"up"}{}

void Block::setLevel(int l){level = l;}

void Block::addCell(Cell &cell){components.emplace_back(cell);}

string Block::agetType(){return type;}

/*
vector<Coord *> Block::calcLeft(){
	vector<Coord *> oldCoords;
	vector<Coord> newCoords;
	for (int comp = 0; comp < 4; comp++){
		oldCoords.emplace_back(component[comp].getCoord()); //get old Coords
		newCoords.emplace_back(Coord(oldCoords[comp]->getX - 1, oldCoords[comp]->getY));
	}
	return newCoords;
}	

vector<Coord *> Block::calcRight(){
	vector<Coord *> oldCoords;
	vector<Coord> newCoords;
	for (int comp = 0; comp < 4; comp++){
		oldCoords.emplace_back(component[comp].getCoord()); //get old Coords
		newCoords.emplace_back(Coord(oldCoords[comp]->getX + 1, oldCoords[comp]->getY));
	}
	return newCoords;
}

vector<Coord *> Block::calcRight(){
	vector<Coord *> oldCoords;
	vector<Coord> newCoords;
	for (int comp = 0; comp < 4; comp++){
		newCoords.emplace_back(component[comp].getCoord()); //get old Coords
		newCoords.emplace_back(Coord(oldCoords[comp]->getX, oldCoords[comp]->getY - 1));
	}
	return newCoords;
}

*/
//vector<Coord *> Block::rotateClock(){
//	beforeCoord = 
//}
