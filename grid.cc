#include "grid.h"
#include "blocki.h"
#include "blockj.h"
#include "blocko.h"
#include "blocks.h"
#include "blockl.h"
#include "blockt.h"
#include "blockz.h"

Grid::Grid()
{

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

//void Grid::nextBlock(){
	//currentBlock = nextBlock;
	// nextBlock = l->createBlock();
//}


void Grid::UpdateGrid(){
	int size = blocksInGrid.size();
	int x = 0;
	int y = 0;

	//for (int i = 0; i < size; ++ i){
		//x = blocksInGrid.at(i).getX();
		//y = blocksInGrid.at(i).getY();
	//	(theGrid.at(x).at(y)).setBlockChar(blocksInGrid.at(i).getType());
	//	(theGrid.at(x).at(y)).setStatus(true);
	//}
}

void Grid::createBlock(std::string blockType,int level){
	if (blockType == "i"){
		BlockI i;
		i.setLevel(level);
		i.addCell(&(theGrid.at(0).at(3)));
		i.addCell(&(theGrid.at(1).at(3)));
		i.addCell(&(theGrid.at(2).at(3)));
		i.addCell(&(theGrid.at(3).at(3)));
		blocksInGrid.emplace_back(i);
		//currentBlock = &blocksInGrid.back();
		theGrid[0][3].setBlockChar("i");
		theGrid[1][3].setBlockChar("i");
		theGrid[2][3].setBlockChar("i");
		theGrid[3][3].setBlockChar("i");
		//UpdateGrid();
	}else if (blockType == "j"){
		BlockJ j;
		j.setLevel(level);
		j.addCell(&(theGrid.at(0).at(2)));
		j.addCell(&(theGrid.at(0).at(3)));
		j.addCell(&(theGrid.at(1).at(3)));
		j.addCell(&(theGrid.at(2).at(3)));
	}else if (blockType == "l"){
		BlockL l;
		l.setLevel(level);
		l.addCell(&(theGrid.at(2).at(2)));
		l.addCell(&(theGrid.at(2).at(3)));
		l.addCell(&(theGrid.at(1).at(3)));
		l.addCell(&(theGrid.at(0).at(3)));
	}else if (blockType == "o"){
		BlockO o;
		o.setLevel(level);
		o.addCell(&(theGrid.at(0).at(2)));
		o.addCell(&(theGrid.at(1).at(2)));
		o.addCell(&(theGrid.at(0).at(3)));
		o.addCell(&(theGrid.at(1).at(3)));
	}else if (blockType == "s"){
		BlockS s;
		s.setLevel(level);
		s.addCell(&(theGrid.at(1).at(2)));
		s.addCell(&(theGrid.at(2).at(2)));
		s.addCell(&(theGrid.at(0).at(3)));
		s.addCell(&(theGrid.at(1).at(3)));
	}else if (blockType == "z"){
		BlockZ z;
		z.setLevel(level);
		z.addCell(&(theGrid.at(0).at(2)));
		z.addCell(&(theGrid.at(1).at(2)));
		z.addCell(&(theGrid.at(1).at(3)));
		z.addCell(&(theGrid.at(2).at(3)));	
	}else{
		BlockT t;
		t.setLevel(level);
		t.addCell(&(theGrid.at(0).at(2)));
		t.addCell(&(theGrid.at(1).at(2)));
		t.addCell(&(theGrid.at(1).at(3)));
		t.addCell(&(theGrid.at(2).at(3)));	
	}


}
