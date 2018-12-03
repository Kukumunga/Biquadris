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



Grid::Grid(Xwindow *w, int displayConst):w{w},displayConstant{displayConst}{
	for (int x = 0; x < 11;++x){ // columns
		std::vector<Cell> vec;
		for (int y = 0; y < 18;++y){ // row
			Cell c = Cell(x,y,w,displayConst);
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

void Grid::drawNext(){
	int colour;
	if (nextBlock->getColour() == "red"){
		colour = 2;
	}else if (nextBlock->getColour() == "orange"){
		colour = 8;
	}else if (nextBlock->getColour() == "darkgreen"){
		colour = 10;
	}else if (nextBlock->getColour() == "blue"){
		colour = 4;
	}else if (nextBlock->getColour() == "yellow"){
		colour = 6;
	}else if (nextBlock->getColour() == "purple"){
		colour = 11;
	}else if (nextBlock->getColour() == "cyan"){
		colour = 5;
	}
	if (w){
		w->fillRectangle(nextBlock->getComp()[0].getX()*20+displayConstant+50, nextBlock->getComp()[0].getY()*20+398,20,20,colour);
		w->fillRectangle(nextBlock->getComp()[1].getX()*20+displayConstant+50, nextBlock->getComp()[1].getY()*20+398,20,20,colour);
		w->fillRectangle(nextBlock->getComp()[2].getX()*20+displayConstant+50, nextBlock->getComp()[2].getY()*20+398,20,20,colour);
		w->fillRectangle(nextBlock->getComp()[3].getX()*20+displayConstant+50, nextBlock->getComp()[3].getY()*20+398,20,20,colour);
	}
}

void Grid::undrawNext(){
	if (w){
		w->fillRectangle(40+displayConstant, 435, 100, 50, Xwindow::White);
	}
}


void Grid::draw(Block *block){
	for (int size = 0;size < block->compSize(); size++){
		theGrid[block->getComp()[size].getX()][block->getComp()[size].getY()].draw();
	}
	if (blind && w){
		blindRect();	
	}
}

void Grid::blindRect(){
	w->fillRectangle(50+displayConstant, 105, 140, 200, Xwindow::Black);	
}

void Grid::undraw(Block *block){
	for (int size = 0;size < block->compSize(); size++){
		theGrid[block->getComp()[size].getX()][block->getComp()[size].getY()].undraw();
	}
}

void Grid::undrawAll(){
	if (w){
		w->fillRectangle(10+displayConstant, 68, 220, 360, Xwindow::White);
	}
	/*
	int numBlocks = blocksInGrid.size();
	for (int block = 0; block < numBlocks; block++){
		undraw(blocksInGrid[block].get());
	}*/
}

void Grid::drawAll(){
	int numBlocks = blocksInGrid.size();
	for (int block = 0; block < numBlocks; block++){
		draw(blocksInGrid[block].get());
	}
}

void Grid::Reset(){
	blocksInGrid.clear();
	turnAllOff();
	heavy = false;
	numClear = 0;
	containsNext = false;
	blind = false;
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
		if (blind){
			if (((r >= 2) && (r < 12)) && ((x >= 2) && (x <9))){
				std::cout << "?";
			}else{
			 	std::cout << theGrid[x][r];
			}
		}else{
			std::cout << theGrid[x][r];
		}
	
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
	blocksInGrid.emplace_back(std::move(nextBlock));//moves the next block into current     
        currentBlock = blocksInGrid.back().get();
	std::vector<Coord> vec = currentBlock->getComp();
	for (int i = 0; i < 4;++i){
		if (isFilled(vec[i].getX(),vec[i].getY())){
			return false;
		}
	}
	UpdateGrid();
	undrawNext();
	draw(currentBlock);
	return true;
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
			if (theGrid[c.getX()][c.getY()].getBlockChar() != "?"){
                		theGrid[c.getX()][c.getY()].setBlockChar(blocksInGrid[i]->agetType());
				theGrid[c.getX()][c.getY()].setBlockColour(blocksInGrid[i]->getColour());
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
	undraw(currentBlock);
	blocksInGrid.pop_back();
	blocksInGrid.emplace_back(std::move(tempBlock));//moves the next block into current     
        currentBlock = blocksInGrid.back().get();
	vec = currentBlock->getComp();
	
        s = vec.size();
        for (int i = 0; i< s;++i){
                theGrid[vec[i].getX()][vec[i].getY()].setBlockChar(currentBlock->agetType());
        	theGrid[vec[i].getX()][vec[i].getY()].setBlockColour(currentBlock->getColour());
	}
	draw(currentBlock);
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
	//notifies cells of its new colour
	/*for (int size = 0; size < 4; size++){
		theGrid[nextBlock->getComp()[size].getX()][nextBlock->getComp()[size].getY()].setBlockColour(nextBlock->getColour());
	}*/
} 

void Grid::turnOff(int x,int y){
	theGrid[x][y].turnOff();
	//std::cout << "undraw" << std::endl;
	//theGrid[x][y].undraw();
}

void Grid::turnOff(){
	std::vector<Coord> vec = currentBlock->getComp();
	for (int i = 0;i < 4;++i){
		Coord c = vec[i];
		theGrid[c.getX()][c.getY()].turnOff();
		//theGrid[c.getX()][c.getY()].undraw();
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
	blind = false;
	if (w){
		undrawAll();
		drawAll();
	}
}

void Grid::turnAllOff(){
	for (int y = 2; y < 18; ++ y){
		for (int x = 0; x < 11; ++x){
			turnOff(x,y);
		}
	}
}

void Grid::Blind(){
	blind = true;
	if (w){
		w->fillRectangle(50+displayConstant, 105, 140, 200, Xwindow::Black);	
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
