#include "grid.h"
#include "blocki.h"
#include "blockj.h"
#include "blocko.h"
#include "blocks.h"
#include "blockl.h"
#include "blockt.h"
#include "blockz.h"
#include "blockstar.h"
#include <vector>
#include <memory>
#include <cmath>
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

bool Grid::validDrop(){
	std::vector<Coord> vec = currentBlock->getComp();
	for (int i = 0;i<4;++i){
		if (vec[i].getY() <= 2){
			return false;
		}
	}
	return true;
}	


int Grid::getCurLevel(){
	return currentBlock->getLevel();
}

void Grid::dropStar(){
	int rowLocation;
	while (!theGrid[5][rowLocation].getStatus()){//while the cells are inactive in the middle
		rowLocation++;//check the cell below
		if (rowLocation == 18){
			break;
		}
	}
	std::cout << theGrid[5][16].getStatus() << std::endl;
	std::cout << theGrid[5][17].getStatus() << std::endl;
	blocksInGrid.emplace_back(new BlockStar());
	blocksInGrid.back().get()->addCoord(Coord{5, rowLocation - 1});
	UpdateGrid();
}

int Grid::blockScore(){
	int score = 0;
	int s = blocksInGrid.size();
	for (int i = s-1;i >= 0;--i){
		std::vector<Coord> vec = blocksInGrid[i]->getComp();
		if (vec.size() == 0){
			score = score + pow((blocksInGrid[i]->getLevel() + 1),2);
			blocksInGrid.erase(blocksInGrid.begin()+i);
		}
	}
			
	return score;
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
	for (int y = 3;y < 18; ++y){
		theGrid[MID][y].alertNeighbours();
		if (theGrid[MID][y].canClearRow()){
			clearRow(y);
			++numClear;
		}
	}
}


void Grid::clearRow(int row){
	int size = blocksInGrid.size();
	for (int e = 0; e < size; ++ e){
		std::vector<Coord> vec = blocksInGrid[e]->getComp();
		int compsize = vec.size();
		for (int n = compsize - 1; n >= 0; --n){
			if (vec[n].getY() == row){
				blocksInGrid[e]->removeComp(n);
				turnOff(vec[n].getX(),row);
			}else if (vec[n].getY() < row){
				blocksInGrid[e]->lowerY(n);
				turnOff(vec[n].getX(),vec[n].getY());
			}
		}
		
	}
}

bool Grid::isFilled(int x,int y){
	return (theGrid.at(x).at(y)).getStatus();
}

bool Grid::next(){//moves nextBlock into currentBlock
	std::vector<Coord> vec = nextBlock->getComp();
	for (int i = 0; i < 4;++i){
		if (isFilled(vec[i].getX(),vec[i].getY())){
			return false;
		}
	}
	blocksInGrid.emplace_back(std::move(nextBlock));//moves the next block into current	
	currentBlock = blocksInGrid.back().get();
	//containsNext = false;
	return true;
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

void Grid::Force(std::string blockType,int level){
	if (blockType == "i"){
		tempBlock = std::unique_ptr<Block>(new BlockI());
		tempBlock->setLevel(level);
		tempBlock->addCoord(Coord{0,3});
		tempBlock->addCoord(Coord{1,3});
		tempBlock->addCoord(Coord{2,3});
		tempBlock->addCoord(Coord{3,3});
	} else if (blockType == "j"){
		tempBlock = std::unique_ptr<Block>(new BlockJ());
		tempBlock->setLevel(level);
		tempBlock->addCoord(Coord{0,2});
		tempBlock->addCoord(Coord{0,3});
		tempBlock->addCoord(Coord{1,3});
		tempBlock->addCoord(Coord{2,3});
	}else if (blockType == "l"){
		tempBlock = std::unique_ptr<Block>(new BlockL());
		tempBlock->setLevel(level);
		tempBlock->addCoord(Coord{2,2});
		tempBlock->addCoord(Coord{2,3});
		tempBlock->addCoord(Coord{1,3});
		tempBlock->addCoord(Coord{0,3});
	}else if (blockType == "o"){
		tempBlock = std::unique_ptr<Block>(new BlockO());
		tempBlock->setLevel(level);
		tempBlock->addCoord(Coord{0,2});
		tempBlock->addCoord(Coord{1,2});
		tempBlock->addCoord(Coord{0,3});
		tempBlock->addCoord(Coord{1,3});
	}else if (blockType == "s"){
		tempBlock = std::unique_ptr<Block>(new BlockS());
		tempBlock->setLevel(level);
		tempBlock->addCoord(Coord{1,2});
		tempBlock->addCoord(Coord{2,2});
		tempBlock->addCoord(Coord{0,3});
		tempBlock->addCoord(Coord{1,3});
	}else if (blockType == "z"){
		tempBlock = std::unique_ptr<Block>(new BlockZ());
		tempBlock->setLevel(level);
		tempBlock->addCoord(Coord{0,2});
		tempBlock->addCoord(Coord{1,2});
		tempBlock->addCoord(Coord{1,3});
		tempBlock->addCoord(Coord{2,3});
	}else{
		tempBlock = std::unique_ptr<Block>(new BlockT());
		tempBlock->setLevel(level);
		tempBlock->addCoord(Coord{0,2});
		tempBlock->addCoord(Coord{1,2});
		tempBlock->addCoord(Coord{2,2});
		tempBlock->addCoord(Coord{1,3});
	}
	std::vector<Coord> vec = currentBlock->getComp();
	int s = vec.size();
	for (int i = 0; i< s;++i){
		turnOff(vec[i].getX(),vec[i].getY());
	}
	blocksInGrid.pop_back();
	blocksInGrid.emplace_back(std::move(tempBlock));//moves the next block into current     
        currentBlock = blocksInGrid.back().get();
	vec = currentBlock->getComp();
        s = vec.size();
        for (int i = 0; i< s;++i){
                theGrid[vec[i].getX()][vec[i].getY()].setBlockChar(currentBlock->agetType());
        }
	
} 
void Grid::createBlock(std::string blockType,int level){
	if (blockType == "i"){
		nextBlock = std::unique_ptr<Block>(new BlockI());
		nextBlock->setLevel(level);
		nextBlock->addCoord(Coord{0,3});
		nextBlock->addCoord(Coord{1,3});
		nextBlock->addCoord(Coord{2,3});
		nextBlock->addCoord(Coord{3,3});
	} else if (blockType == "j"){
		nextBlock = std::unique_ptr<Block>(new BlockJ());
		nextBlock->setLevel(level);
		nextBlock->addCoord(Coord{0,2});
		nextBlock->addCoord(Coord{0,3});
		nextBlock->addCoord(Coord{1,3});
		nextBlock->addCoord(Coord{2,3});
	}else if (blockType == "l"){
		nextBlock = std::unique_ptr<Block>(new BlockL());
		nextBlock->setLevel(level);
		nextBlock->addCoord(Coord{2,2});
		nextBlock->addCoord(Coord{2,3});
		nextBlock->addCoord(Coord{1,3});
		nextBlock->addCoord(Coord{0,3});
	}else if (blockType == "o"){
		nextBlock = std::unique_ptr<Block>(new BlockO());
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
			theGrid[x][y].setBlind();
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

void Grid::unHeavy(){
	heavy = false;
}

void Grid::resetClear(){
	numClear = 0;
}
