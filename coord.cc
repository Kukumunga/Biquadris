#include "coord.h"

int Coord::getX(){
	return x;
}

int Coord::getY(){
	return y;
}

Coord::Coord(int x,int y):x{x},y{y}{}
