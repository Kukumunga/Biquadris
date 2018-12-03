#include "cell.h"
#include "coord.h"
#include <string>

Cell::Cell(int x,int y, Xwindow *w, int displayConst):w{w}, displayConst{displayConst}, c{Coord{x,y}} {}

std::ostream& operator<<(std::ostream &out, Cell &c){
	if (c.getStatus()){
		out << c.getBlockChar();
	}else if (c.getBlockChar() == "?"){
		out << "?";
	}else{
		out << " ";
	}
	return out;
}

void Cell::draw(){
	int intcolour;
	if (colour == "red"){
		intcolour = 2;	
	}else if (colour == "orange"){
		intcolour = 8;
	}else if (colour == "darkgreen"){
		intcolour = 10;
	}else if (colour == "blue"){
		intcolour = 4;
	}else if (colour == "yellow"){
		intcolour = 6;
	}else if (colour == "purple"){
		intcolour = 11;
	}else if (colour == "cyan"){
		intcolour = 5;
	}
	if(w){
		w->fillRectangle((c.getX()*20)+displayConst+10,c.getY()*20+65,width,width,intcolour);//x,y,width,height,colour
	}
}

void Cell::undraw(){
	if (w){
		w->fillRectangle((c.getX()*20)+displayConst+10,c.getY()*20+65,width,width,Xwindow::White);
	}
}

std::string Cell::getBlockChar(){
	return block;
}

void Cell::setBlockColour(std::string col){
	colour = col;
}

void Cell::setBlockChar(std::string c){
	block = c;
	turnOn();
}
void Cell::setBlind(){
	block = "?";
	Filled = false;
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
		signal = 0;
		return true;
	}
	signal = 0;
	return false;
}

void Cell::turnOff(){
	Filled = false;
	block = "";
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
