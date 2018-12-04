#include "board.h"
#include <iostream>
#include <sstream>
#include <memory>
#include <string>
Board::Board(int levelStart,std::string f1,std::string f2,int seed, Xwindow *w):w{w},p1{std::unique_ptr<Player>(new Player(1,levelStart,f1,seed,w,0))},p2{std::unique_ptr<Player>(new Player(2,levelStart,f2,seed,w,250))} {
	//p1->setLevel(levelStart);
	//p2->setLevel(levelStart);
	p1->myTurn();
	if (w){
		initWindow();
	}
}

void Board::clearRows(int player){
	if (player == 1){
		p1->clearRows();
	}else{
		p2->clearRows();
	}
}
void Board::unHeavy(int player){
	if (player == 1){
                p1->unHeavy();
        }else{
                p2->unHeavy();
        }

}
void Board::UpdateGrid(int player){
	if (player == 1){
                p1->UpdateGrid();
        }else{
                p2->UpdateGrid();
        }
}


void Board::calcScore(int player){
	if (player == 1){
                p1->calcScore();
        }else{
                p2->calcScore();
        }
}


void Board::unBlind(int player){
	if (player == 1){
		p1->unBlind();
	}else{
		p2->unBlind();
	}
}

void Board::applySpecial(int player){
	std::string specialAction = "";
	 if (player == 1){
                if (p1->canSpecialAction()){
                	std::cout << "Enter special action:" << std::endl;
                       	std::cin >> specialAction;
                       	applySpecialAction(specialAction,2);
                }
                p1->setClear();
                p1->notMyTurn();
               p2->myTurn();
        }else{
   		if (p2->canSpecialAction()){
			std::cout << "Enter special action:" << std::endl;
                 	std::cin >> specialAction;
                        applySpecialAction(specialAction,1);
               	}
                p2->setClear();
                p2->notMyTurn();
                p1->myTurn();
        }
}

void Board::initWindow(){
	w->drawString(210, 10, "Highscore: " + std::to_string(highscore)); //display HS
	w->drawString(10, 35, "Level:" + std::to_string(p1->getLevel()));//display levels
	w->drawString(260, 35, "Level:" + std::to_string(p2->getLevel()));
	w->drawString(10, 55, "Score:" + std::to_string(p1->getScore()));//display scores
	w->drawString(260, 55, "Score:" + std::to_string(p2->getScore()));
	w->fillRectangle(10, 62, 220, 3, Xwindow::Black);//width of block = 20*11 = 220
	w->fillRectangle(260, 62, 220, 3, Xwindow::Black);
	w->fillRectangle(10, 428, 220, 3, Xwindow::Black);//length of block = 20*18+68 = 428
	w->fillRectangle(260, 428, 220, 3, Xwindow::Black);	
	w->drawString(10, 445, "Next:");//display Next:
	w->drawString(260, 445, "Next:");	
	w->drawString(100, 10, "Player 1");
	w->drawString(350, 10, "Player 2");

	p1->initDisplay();
	p2->initDisplay();
}

int Board::getHighscore()const{
	return highscore;
}

void Board::newHighscore(){
	if (p1->getScore() > highscore){
		highscore = p1->getScore();
		if(w){
			w->fillRectangle(270, 1, 30, 15, Xwindow::White);
			w->drawString(270, 10, std::to_string(highscore));
		}
	}
	if (p2->getScore() > highscore){
		highscore = p2->getScore();
		if(w){
			w->fillRectangle(270, 1, 30, 15, Xwindow::White);
			w->drawString(270, 10, std::to_string(highscore));
		}
	}
}
void Board::noRandom(int playerId,std::string file){
	if (playerId == 1){
		p1->noRandom(file);
	}else{
		p2->noRandom(file);
	}
}

void Board::nextBlock(int playerId){
	if (playerId == 1){
		p1->nextBlock();
	}else{
		p2->nextBlock();
	}
} 

void Board::random(int playerId){
	if (playerId == 1){
                p1->Random();
        }else{
                p2->Random();
        }
}

void Board::createNext(int playerId){
        if (playerId == 1){
                p1->createNext();
        }else{  
                p2->createNext();
        }
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

bool Board::Move(int playerNum,std::string command,int size){
	bool end = false;

	if (command == "left"){
		if (playerNum == 1){
			end = p1->moveBlockLeft(size);
			if (end){
				p1->notMyTurn();
				p2->myTurn();
			}
		}else{
			end = p2->moveBlockLeft(size);
			if (end){
				p2->notMyTurn();
				p1->myTurn();
			}
		}
	}else if (command == "right"){
		if (playerNum == 1){
			end = p1->moveBlockRight(size);
			if (end){
				p1->notMyTurn();
                        	p2->myTurn();
			}
		}else{
			end = p2->moveBlockRight(size);
			if (end){
				p2->notMyTurn();
                        	p1->myTurn();
			}	
		}		
	}else if (command == "down"){
		if (playerNum == 1){
			p1->moveBlockDown(size);
		}else{
			p2->moveBlockDown(size);
		}		
	}else if (command == "drop"){
		if (playerNum == 1){
			p1->dropBlock();
		}else{
			p2->dropBlock();
		}
		end = true;		
	}else if (command == "clockwise"){
		if (playerNum == 1){
			p1->rotateBlockClockwise(size);
		}else{
			p2->rotateBlockClockwise(size);
		}
	}else if (command == "counterclockwise"){
		if (playerNum == 1){
			p1->rotateBlockCounterClockwise(size);
		}else{
			p2->rotateBlockCounterClockwise(size);
		}
	}else if (command == "levelup"){
		if (playerNum == 1){
                        p1->levelUp(size);
                }else{
                        p2->levelUp(size);
                }
	}else if (command == "leveldown"){
		if (playerNum == 1){
                        p1->levelDown(size);
                }else{  
                        p2->levelDown(size);
                }  
	}else{
		if (command == "I"){
			if (playerNum == 1){
				p1->Force("i");
			}else{
				p2->Force("i");
			}
		}else if(command == "J"){
			if (playerNum == 1){
                                p1->Force("j");
                        }else{
                                p2->Force("j");
                        }
		}else if (command == "L"){
			 if (playerNum == 1){
                                p1->Force("l");
                        }else{
                                p2->Force("l");
                        }
		}else if (command == "O"){
			if (playerNum == 1){
                                p1->Force("o");
                        }else{
                                p2->Force("o");
                        } 
		}else if (command == "T"){
			if (playerNum == 1){
                                p1->Force("t");
                        }else{
                                p2->Force("t");
                        }
		}else if (command == "S"){
                        if (playerNum == 1){
                                p1->Force("s");
                       } else{
                                p2->Force("s");
                        }
		}else if (command == "Z"){
                        if (playerNum == 1){
                                p1->Force("z");
                       } else{
                                p2->Force("z");
                        }
		}
	}
	return end;
}

std::ostream& operator<<(std::ostream &out,const Board &b){
	
	out << std::setw(20) << "Highscore: " << b.getHighscore() <<std::endl << std::endl;
	out << "  Player 1           Player 2" << std::endl << std::endl;
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
	out << std::endl;
	return out;
}

void Board::Restart(){
	p2->notMyTurn();		
	p1->Reset();
	p2->Reset();
	p1->myTurn();
//	p1->createNext();
//	p2->createNext();
}
