#include "cell.h"


std::ostream& operator<<(std::ostream &out, Cell &c){
	out << c.getBlockChar();
	return out;
}

char Cell::getBlockChar(){
	return block;
}

Cell::Cell(int x,int y): c{Coord{x,y}} {}

void Cell::addLeftNeighbour(Cell * left){
	leftNeighbour = left;
}

void Cell::addRightNeighbour(Cell * right){
	leftNeighbour = right;
}

void Cell::alertNeighbours(){
	if (Filled){
		leftNeighbour->rightNeighbourFilled();
		rightNeighbour->leftNeighbourFilled();
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
	if (c.getX()  == 5){
		++signal;
	}else{
		leftNeighbour->rightSideFilled();
	}
}

void Cell::leftSideFilled(){
	if (c.getX()  == 5){
		++signal;
	}else{
		rightNeighbour->leftSideFilled();
	}
}

bool Cell::canClearRow(){
	if (signal == 2){
		signal = 0;
		return true;
	}
	return false;
}

void Cell::setStatus(bool stat){
	Filled = stat;
}

bool Cell::getStatus(){
	return Filled;
}

int Cell::getX(){
	return c.getX();
}

int Cell::getY(){
	return c.getY();
}
