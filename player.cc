#include "player.h"
#include <memory>

int Player::getScore() const{
	return score;
}

int Player::getLevel() const{
	return l->getLevel();
}

Player::Player(int id): g{std::unique_ptr<Grid>(new Grid())},l{new Level0("sequence1.txt")}{
	playerId = id;
	l->createBlock(g.get());
	if (g->next() == true){
		g->UpdateGrid();
		l->createBlock(g.get());
	}
}

void Player::Force(std::string b){
	g->Force(b,l->getLevel());
}

void Player::setClear(){
	g->resetClear();
}
void Player::Blind(){
	g->Blind();
}

void Player::Heavy(){
	g->Heavy();
}

bool Player::canSpecialAction(){
	if (g->numCleared() >= 2){
		return true;
	}else{
		return false;
	}
	
}


void Player::levelUp(){
	if (l->getLevel() == 0){
		l.reset(new Level1());
	}else if (l->getLevel() == 1){
		l.reset(new Level2());
	}/*else if (l->getLevel() == 2){
		l->std::reset(new Level3());
	}else if (l->getLevel() == 3){
		l->std::reset(new Level4());
	}else if (l->getLevel() == 4){
		l->std::reset(new Level5());
	}*/	
}


void Player::levelDown(){
	if (l->getLevel() == 1){
                l.reset(new Level0("sequence1.txt"));
        }else if (l->getLevel() == 2){
               // l.reset(new Level1());
        }/*else if (l->getLevel() == 3){
                l->std::reset(new Level2());
        }else if (l->getLevel() == 4){
                l->std::reset(new Level3());
        }else if (l->getLevel() == 5){
                l->std::reset(new Level4());
        }*/
}
void Player::printRow(int r) const{
	g->printRow(r);
}

bool Player::moveBlockLeft(){
	bool end = false;
	end = l->moveLeft(g.get());
	g->UpdateGrid();
	return end;
}

bool Player::moveBlockRight(){
	bool end = false;
	end = l->moveRight(g.get());
	g->UpdateGrid();
	return end;
}

void Player::moveBlockDown(){
	l->moveDown(g.get());
	g->UpdateGrid();
}

void Player::dropBlock(){
	l->dropBlock(g.get());
	g->UpdateGrid();
	g->clearFullRows();
	if (g->next() == false){
		throw playerId;
	}
	g->UpdateGrid();
	l->createBlock(g.get());
	g->unBlind();
	score = score + l->calculateScore(g.get());
	score = score + g->blockScore();
	g->unHeavy();  
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
