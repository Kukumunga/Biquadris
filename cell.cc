#include "cell.h"


std::ostream& operator<<(std::ostream &out, Cell &c){
	out << c.getBlockChar();
	return out;
}

char Cell::getBlockChar(){
	return block;
}

Cell::Cell(int x,int y): c{Cell{x,y}} {}
