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
}

void Grid::printRow(int r){
	for (int x = 0; x < 11; ++ x){
		std::cout << theGrid[x][r];
	}
}

Grid::addToCurrent(){
	blocksInGrid.emplace_back(*currentBlock);
}
