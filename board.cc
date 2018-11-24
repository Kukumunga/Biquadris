#include "board.h"

Board::Board(): p1{Player()},p2{Player()} {}


void Board::printBoards(){	

	for (int i = 0; i < 18; ++i){
		p1.printRow(i);
		std::cout << std::setw(9) << std::setfill(' ');
		p2.printRow(i);
		std::cout << std::endl;
	}
}

void Move(int playerNum,std::string command){
	if (command == "left"){
		if (playerNum == 1){
		//	player1.moveBlockLeft();
		}else{
		//	player2.moveBlockLeft();
		}
	}else if (command == "right"){
		if (playerNum == 1){
			//player1.moveBlockRight();
		}else{
			//player2.moveblockRight();
		}		
	}else if (command == "down"){
		if (playerNum == 1){
			//player1.moveBlockRight();
		}else{
			//player2.moveblockRight();
		}		
	}else if (command == "drop"){
		if (playerNum == 1){
			//player1.dropBlock();
		}else{
			//player2.dropBlock();
		}		
	}
}


std::ostream& operator<<(std::ostream &out, Board &b){

	out << "Level:" << std::setw(5) <<  b.p1.getLevel() <<  std::setfill(' ') << std::setw(14) << std::setfill(' ') 
								<< "Level:" << std::setw(5) <<  b.p2.getLevel() << std::setfill(' ') << std::endl;
	out << "Score:" << std::setw(5) <<  b.p1.getScore() <<  std::setfill(' ') << std::setw(14) << std::setfill(' ') 
								<< "Score:" << std::setw(5) <<  b.p2.getScore() << std::setfill(' ') << std::endl;
	
	for (int i =0; i< 11; ++i){
		out << '-';
	}
	out << std::setw(9);
	for (int i =0; i< 11; ++i){
		out << '-';
	}
	out << std::endl;

	b.printBoards();

	for (int i =0; i< 11; ++i){
		out << '-';
	}
	
	out << std::setw(9);
	for (int i =0; i< 11; ++i){
		out << '-';
	}

	out << std::endl;
	out << "Next:" << std::setw(19) << "Next:" <<std::endl;
	return out;
	
}
