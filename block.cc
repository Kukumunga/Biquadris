#include "block.h"
using namespace std;
#include "cell.h"
#include "coord.h"

Block::~Block(){}

Block::Block(string type, string colour):type{type}, colour{colour},orientation{"up"}{}

void Block::setLevel(int l){level = l;}
int Block::getLevel(){return level;}
void Block::addCoord(Coord coord){components.emplace_back(coord);}

string Block::agetType(){return type;}

vector<Coord> Block::getComp(){return components;}

void Block::lowerY(int position){
	components[position].setCoord(components[position].getX(), components[position].getY() + 1);
}

void Block::removeComp(int position){
	auto it = components.begin()+position;
	components.erase(it);
}

bool Block::isComponent(Coord component){
	for (int comp = 0; comp < 4; comp++){
		if ((component.getX() == components[comp].getX())&&(component.getY() == components[comp].getY())){
			return true;
		}
	}
	return false;
}

void Block::executeLeft(){
	for (int comp = 0; comp < 4; comp++){
		components[comp].setCoord(components[comp].getX()-1, components[comp].getY());
	}
}



void Block::executeRight(){
	for (int comp = 0; comp < 4; comp++){
		components[comp].setCoord(components[comp].getX()+1, components[comp].getY());
	}
}

void Block::executeDown(){
	for (int comp = 0; comp < 4; comp++){
		components[comp].setCoord(components[comp].getX(), components[comp].getY()+1);
	}
}

vector<Coord> Block::calcLeft(){
	vector<Coord> newCoords;
	for (int comp = 0; comp < 4; comp++){
		newCoords.emplace_back(Coord(components[comp].getX() - 1, components[comp].getY()));
	}
	return newCoords;
}	

vector<Coord> Block::calcRight(){
	vector<Coord> newCoords;
	for (int comp = 0; comp < 4; comp++){
		newCoords.emplace_back(Coord(components[comp].getX() + 1, components[comp].getY()));
	}
	return newCoords;
}

vector<Coord> Block::calcDown(){
	vector<Coord> newCoords;
	for (int comp = 0; comp < 4; comp++){
		newCoords.emplace_back(Coord(components[comp].getX(), components[comp].getY() + 1));
	}
	return newCoords;
}

