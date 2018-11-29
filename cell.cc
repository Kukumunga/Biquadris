#include "cell.h"
#include "coord.h"
#include <string>

Cell::Cell(int x,int y): c{Coord{x,y}} {}

std::ostream& operator<<(std::ostream &out, Cell &c){
	if (c.getStatus()){
		out << c.getBlockChar();
	}else{
		out << " ";
	}
	return out;
}

std::string Cell::getBlockChar(){
	return block;
}

void Cell::setBlockChar(std::string c){
	block = c;
	turnOn();
}

void Cell::addLeftNeighbour(Cell * left){
	leftNeighbour = left;
}

void Cell::addRightNeighbour(Cell * right){
	rightNeighbour = right;
}

void Cell::alertNeighbours(){
	if (Filled){
		if ((leftNeighbour != nullptr) && (rightNeighbour != nullptr)){
			leftNeighbour->rightNeighbourFilled();
			rightNeighbour->leftNeighbourFilled();
		}
	}
}

void Cell::rightNeighbourFilled(){
	if (Filled){
		if (leftNeighbour != nullptr){
			leftNeighbour->rightNeighbourFilled();
		}else{
			rightNeighbour->leftSideFilled();
		}
	}
}

void Cell::leftNeighbourFilled(){
	if (Filled){
		if (rightNeighbour != nullptr){
			rightNeighbour->leftNeighbourFilled();
		}else{
			leftNeighbour->rightSideFilled();
		}
	}
}

void Cell::rightSideFilled(){
	if (getX() == 5){
		++signal;
	}else{
		leftNeighbour->rightSideFilled();
	}
}

void Cell::leftSideFilled(){
	if (getX() == 5){
		++signal;
	}else{
		rightNeighbour->leftSideFilled();
	}
}

bool Cell::canClearRow(){
	if (signal == 2){
		return true;
	}
	signal = 0;
	return false;
}

void Cell::turnOff(){
	Filled = false;
}

void Cell::turnOn(){
	Filled = true;
}

bool Cell::getStatus(){
	return Filled;
}

Coord * Cell::getCoord(){
	return &c;
}

int Cell::getX(){
	return c.getX();
}

int Cell::getY(){
	return c.getY();
}

void Cell::setFilledStatus(bool stat){
	Filled = stat;
}
