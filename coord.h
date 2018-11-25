#ifndef __COORD__H
#define __COORD__H


class Coord{

private:
	int x;
	int y;	
public:
	int getX();
	int getY();
	Coord(int,int);
	Coord();
	void setCoord(int,int);
};


#endif
