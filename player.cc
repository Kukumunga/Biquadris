#include "player.h"
#include <memory>

int Player::getScore() const{
	//return score;
	return 1;
}

int Player::getLevel() const{
	return l->getLevel();
}

Player::Player(): g{std::unique_ptr<Grid>(new Grid())},l{new Level0("sequence1.txt")}{
	l->createBlock(g.get());
	g->next();
	g->UpdateGrid();
	l->createBlock(g.get());
}

void Player::levelUp(){
	if (l->getLevel() == 0){
		l.reset(new Level0("sequence1.txt"));
	}else if (l->getLevel() == 1){
		//l->std::reset(new Level2());
	}/*else if (l->getLevel() == 2){
		l->std::reset(new Level3());
	}else if (l->getLevel() == 3){
		l->std::reset(new Level4());
	}else if (l->getLevel() == 4){
		l->std::reset(new Level5());
	}*/	
}

void Player::printRow(int r) const{
	g->printRow(r);
}

void Player::moveBlockLeft(){
	l->moveLeft(g.get());
	g->UpdateGrid();
}

void Player::moveBlockRight(){
	l->moveRight(g.get());
	g->UpdateGrid();
}

void Player::moveBlockDown(){
	l->moveDown(g.get());
	g->UpdateGrid();
}

void Player::dropBlock(){
	l->dropBlock(g.get());
	g->UpdateGrid();
	g->clearFullRows();
	g->next();
	g->UpdateGrid();
	l->createBlock(g.get());
	  
}

void Player::printNextBlock(int line) const{
	if (turn){
		g->printNextBlock(line);
	}else{
		std::cout << "     ";
	}
}

void Player::myTurn(){
	turn = true;
}

void Player::notMyTurn(){
	turn = false;
}

void Player::rotateBlockClockwise(){
	l->rotateBlockClock(g.get());
	g->UpdateGrid();
}

void Player::rotateBlockCounterClockwise(){
	l->rotateBlockCounterClock(g.get());
	g->UpdateGrid();
}
