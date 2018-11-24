#include "block.h"
using namespace std;
#include "cell.h"
#include "coord.h"

Block::Block():orientation{"up"}{}

void Block::setLevel(int l){level = l;}

void Block::addCell(Cell *cell){components.emplace_back(cell);}

vector<Coord *> Block::calcLeft(){
	vector<Coord *> newCoords;
	for (int comp = 0; comp < 4; comp++){
		beforeCoords.emplace_back(component[comp].getCoord()); //get old Coords
	}
	
}	

//vector<Coord *> Block::rotateClock(){
//	beforeCoord = 
//}
