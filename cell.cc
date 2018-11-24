#include "cell.h"


std::ostream& operator<<(std::ostream &out, Cell &c){
	out << c.getBlockChar();
	return out;
}

char Cell::getBlockChar(){
	return block;
}

Cell::Cell(int x,int y): c{Cell{x,y}} {}

void Cell::addLeftNeighbour(Cell * left){
	leftNeighbour = left;
}

void Cell::addRightNeighbour(Cell * right){
	leftNeighbour = right;
}

void Cell::alertNeighbours(){
	if (Filled){
		left->rightNeighbourFilled();
		right->LeftNeighbourFilled();
	}
}

void Cell::rightNeighbourFilled(){
	if (Filled){
		if (left != nullptr){
			left->rightNeighbourFilled();
		}else{
			right->LeftSideFilled();
		}
	}
}

void Cell::leftNeighbourFilled(){
	if (Filled){
		if (right != nullptr){
			right->leftNeighbourFilled();
		}else{
			left->rightSideFilled();
		}
	}
}

void Cell::rightSideFilled(){
	if (c.getX()  == 5){
		++signal;
	}else{
		left->rightSideFilled();
	}
}

void Cell::leftSideFilled(){
	if (c.getX()  == 5){
		++signal;
	}else{
		right->leftSideFilled();
	}
}

bool canClearRow(){
	if (signal == 2){
		signal = 0;
		return true;
	}
}

void Cell::setFilledStatus(bool stat){
	Filled = stat;
}

bool Cell::getFilledStatus(){
	return Filled;
}

int Cell::getX(){
	return c.getX();
}

int Cell::getY(){
	return c.getY();
}