#include "coord.h"

Coord::Coord(int x,int y):x{x},y{y}{}

int Coord::getX(){
	return x;
}

int Coord::getY(){
	return y;
}

void Coord::setCoord(int newX, int newY){
	x = newX;
	y = newY;
}
