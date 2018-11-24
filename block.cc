#include "block.h"
using namespace std;
#include "cell.h"
#include "coord.h"

Block::Block():orientation{"up"}{}

Block::setLevel(int l){level = l;}

Block::addCell(Cell *cell){components.emplace_back(cell);}



//vector<Coord *> Block::rotateClock(){
//	beforeCoord = 
//}
