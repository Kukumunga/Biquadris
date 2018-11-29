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
	for (int y = 3; y < 18 ; ++y){
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


int Grid::numCleared(){
	return numClear;
}


void Grid::printRow(int r){
	for (int x = 0; x < 11; ++ x){
		std::cout << theGrid[x][r];
	}
}

void Grid::addToCurrent(){
	containsNext = false;
}

// check if rows and be clear if so clear the row

void Grid::clearFullRows(){
	for (int y = 17;y < 18; ++y){
		theGrid[MID][y].alertNeighbours();
		if (theGrid[MID][y].canClearRow()){
			clearRow(y);
			++numClear;
		}
	}
}


void Grid::clearRow(int row){
	for (int x = 0; x < 11;++x){
		int size = blocksInGrid.size();
		for (int e = 0; e < size; ++ e){
			std::vector<Coord> vec = blocksInGrid[e]->getComp();
			int compsize = vec.size();
			for (int n = compsize - 1; n >= 0; --n){
				if ((vec[n].getX() == x) && (vec[n].getY() == row)){
					blocksInGrid[e]->removeComp(n);
					turnOff(x,row);
				}else if (vec[n].getX() == x){
					blocksInGrid[e]->lowerY(n);
					turnOff(x,vec[n].getY());
				}
			}
		}
	}
}

bool Grid::isFilled(int x,int y){
	return (theGrid.at(x).at(y)).getStatus();
}

void Grid::next(){//moves nextBlock into currentBlock
	blocksInGrid.emplace_back(std::move(nextBlock));//moves the next block into current
	currentBlock = blocksInGrid.back().get();
	//containsNext = false;
}


Block* Grid::getCurrentBlock(){
	return currentBlock;
}


void Grid::UpdateGrid(){
	int size;
	if (blind != true){
		if (!containsNext){
			size = blocksInGrid.size();
		}else{
			size = blocksInGrid.size() - 1;
		}
		for (int i = 0; i < size;++i){
			std::vector<Coord> vec = blocksInGrid[i]->getComp();
			int s = vec.size();
			for (int j = 0;j < s;++j){
                		Coord c = vec[j];
                		theGrid[c.getX()][c.getY()].setBlockChar(blocksInGrid[i]->agetType());
			}	
  		}
	}
}

void Grid::createBlock(std::string blockType,int level){
	if (blockType == "i"){
		nextBlock = std::unique_ptr<Block>(new BlockI());
		//blocksInGrid.emplace_back(new BlockI());
		nextBlock->setLevel(level);
		nextBlock->addCoord(Coord{0,3});
		nextBlock->addCoord(Coord{1,3});
		nextBlock->addCoord(Coord{2,3});
		nextBlock->addCoord(Coord{3,3});
		//nextBlock = blocksInGrid.back().get();
	} else if (blockType == "j"){
		nextBlock = std::unique_ptr<Block>(new BlockJ());
		//blocksInGrid.emplace_back(new BlockJ());
		nextBlock->setLevel(level);
		nextBlock->addCoord(Coord{0,2});
		nextBlock->addCoord(Coord{0,3});
		nextBlock->addCoord(Coord{1,3});
		nextBlock->addCoord(Coord{2,3});
		//nextBlock = blocksInGrid.back().get();
	}else if (blockType == "l"){
		nextBlock = std::unique_ptr<Block>(new BlockL());
		//blocksInGrid.emplace_back(new BlockL());
		nextBlock->setLevel(level);
		nextBlock->addCoord(Coord{2,2});
		nextBlock->addCoord(Coord{2,3});
		nextBlock->addCoord(Coord{1,3});
		nextBlock->addCoord(Coord{0,3});
		//nextBlock = blocksInGrid.back().get();
	}else if (blockType == "o"){
		nextBlock = std::unique_ptr<Block>(new BlockO());
		//blocksInGrid.emplace_back(new BlockO());
		nextBlock->setLevel(level);
		nextBlock->addCoord(Coord{0,2});
		nextBlock->addCoord(Coord{1,2});
		nextBlock->addCoord(Coord{0,3});
		nextBlock->addCoord(Coord{1,3});
		//nextBlock = blocksInGrid.back().get();
	}else if (blockType == "s"){
		nextBlock = std::unique_ptr<Block>(new BlockS());
		//blocksInGrid.emplace_back(new BlockS());
		nextBlock->setLevel(level);
		nextBlock->addCoord(Coord{1,2});
		nextBlock->addCoord(Coord{2,2});
		nextBlock->addCoord(Coord{0,3});
		nextBlock->addCoord(Coord{1,3});
		//nextBlock = blocksInGrid.back().get();
	}else if (blockType == "z"){
		nextBlock = std::unique_ptr<Block>(new BlockZ());
		//blocksInGrid.emplace_back(new BlockZ());
		nextBlock->setLevel(level);
		nextBlock->addCoord(Coord{0,2});
		nextBlock->addCoord(Coord{1,2});
		nextBlock->addCoord(Coord{1,3});
		nextBlock->addCoord(Coord{2,3});
		//nextBlock = blocksInGrid.back().get();
	}else{
		nextBlock = std::unique_ptr<Block>(new BlockT());
		//blocksInGrid.emplace_back(new BlockT());
		nextBlock->setLevel(level);
		nextBlock->addCoord(Coord{0,2});
		nextBlock->addCoord(Coord{1,2});
		nextBlock->addCoord(Coord{2,2});
		nextBlock->addCoord(Coord{1,3});
		//nextBlock = blocksInGrid.back().get();
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
	if (nextBlock!= nullptr){
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
}

void Grid::unBlind(){
	if (blind == true){
		turnAllOff();
		blind = false;
		UpdateGrid();
	}
}

void Grid::turnAllOff(){
	for (int y = 3; y < 18; ++ y){
		for (int x = 0; x < 11; ++x){
			turnOff(x,y);
		}
	}
}

void Grid::Blind(){
	blind = true;
	for (int y = 3; y< 14;++y){
		for (int x = 2 ; x < 9; ++x){
			turnOn(x,y);
			theGrid[x][y].setBlockChar("?");
		}
	}
}

void Grid::Heavy(){
	heavy = true;
}

bool Grid::getHeavy(){
	return heavy;
}

void Grid::turnOn(int x,int y){
	theGrid[x][y].turnOn();
}
