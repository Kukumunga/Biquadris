#include "board.h"
#include <iostream>
#include <memory>

Board::Board(): p1{std::unique_ptr<Player>(new Player(1))},p2{std::unique_ptr<Player>(new Player(2))} {
	p1->myTurn();
}

void Board::applySpecialAction(std::string action, int player){
	if (action == "blind"){
		if (player == 1){
			p1->Blind();
		}else{
			p2->Blind();
		}
	}else if(action == "force"){
		std::string b = "";
		std::cout << "Enter block letter:"<<std::endl;
		std::cin >> b;
	 	if (player == 1){
                        p1->Force(b);
                }else{
                       p2->Force(b);
                }
	}else if (action == "heavy"){
		if (player == 1){
                        p1->Heavy();
                }else{
                        p2->Heavy();
                }
	}
}


void Board::printBoards() const{	
	for (int i = 0; i < 18; ++i){
		p1->printRow(i);
		std::cout << std::setw(9) << std::setfill(' ');
		p2->printRow(i);
		std::cout << std::endl;
	}
}

bool Board::Move(int playerNum,std::string command){
	std::string specialAction = "";
	bool end = false;

	if (command == "left"){
		if (playerNum == 1){
			end = p1->moveBlockLeft();
		}else{
			end = p2->moveBlockLeft();
		}
	}else if (command == "right"){
		if (playerNum == 1){
			end = p1->moveBlockRight();
		}else{
			end = p2->moveBlockRight();
		}		
	}else if (command == "down"){
		if (playerNum == 1){
			p1->moveBlockDown();
		}else{
			p2->moveBlockDown();
		}		
	}else if (command == "drop"){
		if (playerNum == 1){
			p1->dropBlock();
			if (p1->canSpecialAction()){
				std::cout << "Enter special action:" << std::endl;
				std::cin >> specialAction;
				applySpecialAction(specialAction,2);
			} 
			p1->notMyTurn();
			p2->myTurn();
		}else{
			p2->dropBlock();
			if (p2->canSpecialAction()){
                                std::cin >> specialAction;
                                applySpecialAction(specialAction,1);
                        }
			p2->notMyTurn();
			p1->myTurn();
		}		
	}else if (command == "clockwise"){
		if (playerNum == 1){
			p1->rotateBlockClockwise();
		}else{
			p2->rotateBlockClockwise();
		}
	}else if (command == "counterclockwise"){
		if (playerNum == 1){
			p1->rotateBlockCounterClockwise();
		}else{
			p2->rotateBlockCounterClockwise();
		}
	}else if (command == "levelup"){
		if (playerNum == 1){
                        p1->levelUp();
                }else{
                        p2->levelUp();
                }
	}else if (command == "leveldown"){
		if (playerNum == 1){
                        //p1->levelDown();
                }else{  
                        //p2->levelDown();
                }  
	}

	//	return end;
}

std::ostream& operator<<(std::ostream &out,const Board &b){
	out << "Level:" << std::setw(5) <<  b.p1->getLevel() <<  std::setfill(' ') << std::setw(14) << std::setfill(' ') 
								<< "Level:" << std::setw(5) <<  b.p2->getLevel() << std::setfill(' ') << std::endl;
	out << "Score:" << std::setw(5) <<  b.p1->getScore() <<  std::setfill(' ') << std::setw(14) << std::setfill(' ') 
								<< "Score:" << std::setw(5) <<  b.p2->getScore() << std::setfill(' ') << std::endl;
	
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
	b.p1->printNextBlock(1);
	out << std::setw(19);
	b.p2->printNextBlock(1);
	out <<std::endl;
	b.p1->printNextBlock(2);
	out << std::setw(19);
	b.p2->printNextBlock(2);
	return out;
}
