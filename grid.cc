#include "grid.h"
#include "blocki.h"
#include "blockj.h"
#include "blocko.h"
#include "blocks.h"
#include "blockl.h"
#include "blockt.h"
#include "blockz.h"
#include <vector>
#include <memory>
using namespace std;

Grid::Grid(){

	for (int x = 0; x < 11;++x){ // columns
		std::vector<Cell> vec;
		for (int y = 0; y < 18;++y){ // row
			Cell c = Cell(x,y);
			vec.emplace_back(c);
		}
		theGrid.emplace_back(vec);
	}

	// add left right neighbours
	// row 0,1,2 is reserved
	for (int y = 3; y < 15 ; ++y){
		for (int x = 0; x < 11; ++x){
			try{
                theGrid[x][y].addLeftNeighbour(&theGrid.at(x-1).at(y));
            }catch (std::out_of_range){}
            try{
                theGrid[x][y].addRightNeighbour(&theGrid.at(x+1).at(y));
            }catch (std::out_of_range){}
		}
	}
}

void Grid::printRow(int r){
	for (int x = 0; x < 11; ++ x){
		std::cout << theGrid[x][r];
	}
}

void Grid::addToCurrent(){
	blocksInGrid.emplace_back(shared_ptr<Block>(currentBlock));
}

// check if rows and be clear if so clear the row

void Grid::clearFullRows(){
	for (int y = 3;y < 15; ++y){
		theGrid[MID][y].alertNeighbours();
		if (theGrid[MID][y].canClearRow()){
			//std::cout << y;
			clearRow(y);
		}
	}

}


void Grid::clearRow(int row){

	for (int i = row; i > 3; --i){
		for (int x = 0; x < 11; ++x){
			theGrid[x][i].setFilledStatus(isFilled(x,i-1));
			theGrid[x][i].setBlockChar(theGrid[x][i-1].getBlockChar());
		}
	}

	//	 clear row 3
	for (int x = 0; x < 11; ++x){
		theGrid[x][3].turnOff();
	}
}

bool Grid::isFilled(int x,int y){
	return (theGrid.at(x).at(y)).getStatus();
}

void Grid::next(){
	currentBlock = nextBlock;
	nextBlock = nullptr;
	blocksInGrid.emplace_back(shared_ptr<Block>(currentBlock));
}


Block* Grid::getCurrentBlock(){
	return currentBlock;
}


void Grid::UpdateGrid(){
	int size = blocksInGrid.size();
	for (int i = 0; i < size;++i){
		std::vector<Coord> vec = blocksInGrid[i]->getComp();
		int s = vec.size();
		for (int j = 0;j < s;++j){
                	Coord c = vec[j];
                	theGrid[c.getX()][c.getY()].setBlockChar(blocksInGrid[i]->agetType());
		}
  	}
}

void Grid::createBlock(std::string blockType,int level){
	if (blockType == "i"){
		Block *i = new BlockI();
		i->setLevel(level);
		i->addCoord(Coord{0,3});
		i->addCoord(Coord{1,3});
		i->addCoord(Coord{2,3});
		i->addCoord(Coord{3,3});
		nextBlock = i;
	} else if (blockType == "j"){
		Block *j = new BlockJ();
		j->setLevel(level);
		j->addCoord(Coord{0,2});
		j->addCoord(Coord{0,3});
		j->addCoord(Coord{1,3});
		j->addCoord(Coord{2,3});
		nextBlock = j;
	}else if (blockType == "l"){
		BlockL *l = new BlockL();
		l->setLevel(level);
		l->addCoord(Coord{2,2});
		l->addCoord(Coord{2,3});
		l->addCoord(Coord{1,3});
		l->addCoord(Coord{0,3});
		nextBlock = l;
	}else if (blockType == "o"){
		BlockO *o = new BlockO();
		o->setLevel(level);
		o->addCoord(Coord{0,2});
		o->addCoord(Coord{1,2});
		o->addCoord(Coord{0,3});
		o->addCoord(Coord{1,3});
		nextBlock = o;
	}else if (blockType == "s"){
		BlockS *s = new BlockS();
		s->setLevel(level);
		s->addCoord(Coord{1,2});
		s->addCoord(Coord{2,2});
		s->addCoord(Coord{0,3});
		s->addCoord(Coord{1,3});
		nextBlock = s;
	}else if (blockType == "z"){
		BlockZ *z = new BlockZ();
		z->setLevel(level);
		z->addCoord(Coord{0,2});
		z->addCoord(Coord{1,2});
		z->addCoord(Coord{1,3});
		z->addCoord(Coord{2,3});
		nextBlock = z;
	}else{
		BlockT *t = new BlockT();
		t->setLevel(level);
		t->addCoord(Coord{0,2});
		t->addCoord(Coord{1,2});
		t->addCoord(Coord{2,2});
		t->addCoord(Coord{1,3});
		nextBlock = t;
	}
} 

void Grid::turnOff(int x,int y){
	theGrid[x][y].turnOff();
}

void Grid::turnOff(){
	std::vector<Coord> vec = currentBlock->getComp();
	for (int i = 0;i < 4;++i){
		Coord c = vec[i];
		theGrid[c.getX()][c.getY()].turnOff();
	}
}

void Grid::printNextBlock(int line){
	std::string type = nextBlock->agetType();
	if (line == 1){
		if (type == "I"){
			std::cout << "     ";
		}else if (type == "J"){
			std::cout << "J    ";
		}else if (type == "L"){
			std::cout <<"  L  ";
		}else if (type == "O"){
			std::cout <<"OO   ";
		}else if (type == "S"){
			std::cout << " SS  ";
		}else if (type == "Z"){
			std::cout << "ZZ   ";
		}else if (type == "T"){
			std::cout << "TTT  ";
		}
	}else{
		if (type == "I"){
			std::cout << "IIII ";
		}else if (type == "J"){
			std::cout << "JJJ  ";
		}else if (type == "L"){
			std::cout <<"LLL  ";
		}else if (type == "O"){
			std::cout <<"OO   ";
		}else if (type == "S"){
			std::cout << "SS   ";
		}else if (type == "Z"){
			std::cout << " ZZ  ";
		}else if (type == "T"){
			std::cout << " T   ";
		}
	}
}
