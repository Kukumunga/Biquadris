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
	}else if (l->getLevel() == 2){
		l.reset(new Level3());
	}else if (l->getLevel() == 3){
		l.reset(new Level4());
	}	
}


void Player::levelDown(){
	if (l->getLevel() == 1){
                l.reset(new Level0("sequence1.txt"));
        }else if (l->getLevel() == 2){
                l.reset(new Level1());
        }else if (l->getLevel() == 3){
                l.reset(new Level2());
        }else if (l->getLevel() == 4){
                l.reset(new Level3());
        }
}
void Player::printRow(int r) const{
	g->printRow(r);
}

bool Player::moveBlockLeft(int m){
	bool end = false;
	end = l->moveLeft(g.get(),m);
	g->UpdateGrid();
	return end;
}

bool Player::moveBlockRight(int m){
	bool end = false;
	end = l->moveRight(g.get(),m);
	g->UpdateGrid();
	return end;
}

void Player::moveBlockDown(int m){
	l->moveDown(g.get(),m);
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

void Player::rotateBlockClockwise(int m){
	l->rotateBlockClock(g.get(),m);
	g->UpdateGrid();
}

void Player::rotateBlockCounterClockwise(int m){
	l->rotateBlockCounterClock(g.get(),m);
	g->UpdateGrid();
}

void Player::noRandom(std::string file){
	if ((l->getLevel() == 3) || (l->getLevel() == 4)){
	//	l->noRandom(file);
	}
}

int Player::getLevel(){
	return l->getLevel();
}

void Player::Random(){
//	l->Random();
}
