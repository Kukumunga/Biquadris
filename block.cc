#include "block.h"
using namespace std;
#include "cell.h"
#include "coord.h"
#include <vector>

Block::Block():orientation{"up"}{}

Block::setLevel(int l){level = l;}

Block::addCell(Cell *cell){components.emplace_back(cell);}

vector<Coord *> Block::calcLeft(){
	vector<Coord *> newCoords;
	for (int comp = 0; comp < 4; comp++){
		beforeCoords.emplace_back(component[comp].getCoord()); //get old Coords
	}
	
}	

//vector<Coord *> Block::rotateClock(){
//	beforeCoord = 
//}
