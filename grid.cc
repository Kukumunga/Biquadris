#include "grid.h"
#include "blocki.h"
#include "blockj.h"
#include "blocko.h"
#include "blocks.h"
#include "blockl.h"
#include "blockt.h"
#include "blockz.h"
#include <vector>

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
	blocksInGrid.emplace_back(*currentBlock);
}

// check if rows and be clear if so clear the row

void Grid::clearFullRows(){
	for (int y = 3;y < 15; ++y){
		theGrid[MID][y].alertNeighbours();
		if (theGrid[MID][y].canClearRow()){
			clearRow(y);
		}
	}

}


void Grid::clearRow(int row){
	//for (int i = row; i > 3; --i){
	//	for (int x = 0; x < 11; ++x){
	//		theGrid[x][i].setFilledStatus(theGrid[x][i-1].getFilledStatus());
	//		theGrid[x][i].setBlockChar(theGrid[x][i-1].getBlockChar());
	//	}
	//}

	// clear row 3
	//for (int x = 0; x < 11; ++ x){
	//	theGrid[x][3].setFilledStatus(false);
//	}
}

bool Grid::isFilled(int x,int y){
	return (theGrid.at(x).at(y)).getStatus();
}

void Grid::next(){
	currentBlock = nextBlock;
	nextBlock = nullptr;
}


Block* Grid::getCurrentBlock(){
	return currentBlock;
}

void Grid::UpdateGrid(){
	std::vector<Coord> vec = currentBlock->getComp();
	for (int i = 0;i < 4;++i){
		Coord c = vec[i];
		theGrid[c.getX()][c.getY()].setBlockChar(currentBlock->agetType());
	}
}

void Grid::createBlock(std::string blockType,int level){
	if (blockType == "i"){
		BlockI i;
		i.setLevel(level);
		i.addCoord(Coord{0,3});
		i.addCoord(Coord{1,3});
		i.addCoord(Coord{2,3});
		i.addCoord(Coord{3,3});
		blocksInGrid.emplace_back(i);
		nextBlock = &blocksInGrid.back();
		currentBlock = nextBlock;
		//theGrid[0][3].setBlockChar("I");
		//theGrid[1][3].setBlockChar("I");
		//theGrid[2][3].setBlockChar("I");
		//theGrid[3][3].setBlockChar("I");
	}/* else if (blockType == "j"){
		BlockJ j;
		j.setLevel(level);
		j.addCell(&theGrid[0][2]);
		j.addCell(&theGrid[0][3]);
		j.addCell(&theGrid[1][3]);
		j.addCell(&theGrid[2][3]);
		blocksInGrid.emplace_back(j);
		theGrid[0][2].setBlockChar("J");
		theGrid[0][3].setBlockChar("J");
		theGrid[1][3].setBlockChar("J");
		theGrid[2][3].setBlockChar("J");
	}else if (blockType == "l"){
		BlockL l;
		l.setLevel(level);
		l.addCell(&theGrid[2][2]);
		l.addCell(&theGrid[2][3]);
		l.addCell(&theGrid[1][3]);
		l.addCell(&theGrid[0][3]);
		blocksInGrid.emplace_back(l);
		theGrid[2][2].setBlockChar("L");
		theGrid[2][3].setBlockChar("L");
		theGrid[1][3].setBlockChar("L");
		theGrid[0][3].setBlockChar("L");
	}else if (blockType == "o"){
		BlockO o;
		o.setLevel(level);
		o.addCell(&theGrid[0][2]);
		o.addCell(&theGrid[1][2]);
		o.addCell(&theGrid[0][3]);
		o.addCell(&theGrid[1][3]);
		blocksInGrid.emplace_back(o);
		theGrid[0][2].setBlockChar("O");
		theGrid[1][2].setBlockChar("O");
		theGrid[0][3].setBlockChar("O");
		theGrid[1][3].setBlockChar("O");
	}else if (blockType == "s"){
		BlockS s;
		s.setLevel(level);
		s.addCell(&theGrid[1][2]);
		s.addCell(&theGrid[2][2]);
		s.addCell(&theGrid[0][3]);
		s.addCell(&theGrid[1][3]);
		blocksInGrid.emplace_back(s);
		theGrid[1][2].setBlockChar("S");
		theGrid[2][2].setBlockChar("S");
		theGrid[0][3].setBlockChar("S");
		theGrid[1][3].setBlockChar("S");
	}else if (blockType == "z"){
		BlockZ z;
		z.setLevel(level);
		z.addCell(&theGrid[0][2]);
		z.addCell(&theGrid[1][2]);
		z.addCell(&theGrid[1][3]);
		z.addCell(&theGrid[2][3]);	
		blocksInGrid.emplace_back(z);
		theGrid[0][2].setBlockChar("Z");
		theGrid[1][2].setBlockChar("Z");
		theGrid[1][3].setBlockChar("Z");
		theGrid[2][3].setBlockChar("Z");
	}else{
		BlockT t;
		t.setLevel(level);
		t.addCell(&theGrid[0][2]);
		t.addCell(&theGrid[1][2]);
		t.addCell(&theGrid[2][2]);
		t.addCell(&theGrid[1][3]);	
		blocksInGrid.emplace_back(t);
		theGrid[0][2].setBlockChar("T");
		theGrid[1][2].setBlockChar("T");
		theGrid[2][2].setBlockChar("T");
		theGrid[1][3].setBlockChar("T");
	}*/
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
			std::cout <<"   L  ";
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
