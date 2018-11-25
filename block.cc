#include "block.h"
using namespace std;
#include "cell.h"
#include "coord.h"

Block::~Block(){
	components.clear();
}

Block::Block(string type, string colour):type{type}, colour{colour},orientation{"up"}{}

void Block::setLevel(int l){level = l;}

void Block::addCoord(Coord *coord){components.emplace_back(coord);}

string Block::agetType(){return type;}

void Block::executeLeft(){
	for (int comp = 0; comp < 4; comp++){
		components[comp]->setCoord(components[comp]->getX()-1, components[comp]->getY());
	}
}

void Block::executeRight(){
	for (int comp = 0; comp < 4; comp++){
		components[comp]->setCoord(components[comp]->getX()+1, components[comp]->getY());
	}
}

void Block::executeDown(){
	for (int comp = 0; comp < 4; comp++){
		components[comp]->setCoord(components[comp]->getX(), components[comp]->getY()-1);
	}
}

vector<Coord> Block::calcLeft(){
	vector<Coord *> oldCoords;
	vector<Coord> newCoords;
	for (int comp = 0; comp < 4; comp++){
		newCoords.emplace_back(Coord(components[comp]->getX() - 1, components[comp]->getY()));
	}
	return newCoords;
}	

vector<Coord> Block::calcRight(){
	vector<Coord *> oldCoords;
	vector<Coord> newCoords;
	for (int comp = 0; comp < 4; comp++){
		newCoords.emplace_back(Coord(components[comp]->getX() + 1, components[comp]->getY()));
	}
	return newCoords;
}

vector<Coord> Block::calcDown(){
	vector<Coord *> oldCoords;
	vector<Coord> newCoords;
	for (int comp = 0; comp < 4; comp++){
		newCoords.emplace_back(Coord(components[comp]->getX(), components[comp]->getY() - 1));
	}
	return newCoords;
}


//vector<Coord *> Block::rotateClock(){
//	beforeCoord = 
//}
