#include "grid.h"

Grid::Grid(){

	for (int x = 0; x < 11;++x){ // columns
		std::vector<Cell> vec;
		for (int y = 0; y < 18;++y){ // row
			Cell c = Cell();
			vec.emplace_back(c);
		}
		theGrid.emplace_back(vec);
	}

	// add left right neighbours
	// row 0,1,2 is reserved
	for (int y = 3; y < 15 ; ++y){
		for (int x = 0; x < 11; ++x){
			try{
                theGrid[j][k].addLeftNeighbour(&theGrid.at(x-1).at(y));
            }catch (std::out_of_range){}
            try{
                theGrid[j][k].addRightNeighbour(&theGrid.at(x+1).at(y));
            }catch (std::out_of_range){}
		}
	}	
}

void Grid::printRow(int r){
	for (int x = 0; x < 11; ++ x){
		std::cout << theGrid[x][r];
	}
}

Grid::addToCurrent(){
	blocksInGrid.emplace_back(*currentBlock)
}

Grid::clearFullRows(){
	for (int y = 3;y < 15; ++y){
		theGrid[MID][y].alertNeighbours();
		if (theGrid[MID][y].canClearRow()){
			clearRow(y);
		}
	}
}


Grid::clearRow(int row){
	for (int i = row; i < 3; --i){
		for (int x = 0; x < 11;){
			theGrid[x][i].setStatus(theGrid[x][i-1].getStatus());
			theGrid[x][i].setBlockChar(theGrid[x][i-1].getBlockChar());
		}
	}

	// clear row 3

}

