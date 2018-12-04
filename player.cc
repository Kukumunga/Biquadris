#include "player.h"
#include <memory>

int Player::getScore() const{
	return score;
}

int Player::getLevel() const{
	return l->getLevel();
}

void Player::Reset(){
	g->undrawAll();
	g->undrawNext();
	g->Reset();
	score = 0;
	l.reset(new Level0(f));
	l->createBlock(g.get());
	if (g->next() == true){
		l->createBlock(g.get());
	}
	if (w){
		w->fillRectangle(45+displayConst, 40, 10, 15, Xwindow::White);
		w->drawString(46+displayConst, 55, "0");
		w->fillRectangle(45+displayConst, 25, 10, 15, Xwindow::White); //clear old level
		w->drawString(46+displayConst, 35, "0");

	}
	g->UpdateGrid();
	g->drawAll();	
}

void Player::initDisplay(){
	g->draw(g->getCurrentBlock());	
}

Player::Player(int id,std::string f,int seed, Xwindow *w, int displayConst):w{w},displayConst{displayConst},g{std::unique_ptr<Grid>(new Grid(w, displayConst))},l{new Level0(f)},seed{seed},f{f}{
	playerId = id;
	l->createBlock(g.get());
	if (g->next() == true){
		g->UpdateGrid();
		l->createBlock(g.get());
	}
}

void Player::clearRows(){
	g->clearFullRows();	
}


void Player::createNext(){
	l->createBlock(g.get());
}

void Player::nextBlock(){
	if (g->next() == false){
		throw playerId;
	}
}

void Player::Force(std::string b){
	g->Force(b,l->getLevel());
}

void Player::setClear(){
	if (g->numCleared() >= 1){
		if (l->getLevel() == 4){
			l->resetCounter();
		}	
		g->resetClear();
	}
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


void Player::levelUp(int m){
	for (int i = 0;i < m;++i){
		if (l->getLevel() == 0){
			l.reset(new Level1(seed));
		}else if (l->getLevel() == 1){
			l.reset(new Level2(seed));
		}else if (l->getLevel() == 2){
			l.reset(new Level3(seed));
		}else if (l->getLevel() == 3){
			l.reset(new Level4(seed));
		}	
	}
	if (w){
		w->fillRectangle(45+displayConst, 25, 10, 15, Xwindow::White); //clear old level
		w->drawString(46+displayConst, 35, std::to_string(getLevel()));
	}
}

void Player::setLevel(int newLevel){
	if (newLevel  == 1){
        	l.reset(new Level1(seed));
        }else if (newLevel == 2){
                l.reset(new Level2(seed));
        }else if (newLevel == 3){
               	l.reset(new Level3(seed));
        }else if (newLevel == 4){
                l.reset(new Level4(seed));
        }
	if (w){
		w->fillRectangle(45+displayConst, 25, 10, 15, Xwindow::White); //clear old level
		w->drawString(46+displayConst, 35, std::to_string(getLevel()));
	}
}

void Player::levelDown(int m){
	for (int i = 0;i < m;++i){
		if (l->getLevel() == 1){
                	l.reset(new Level0(f));
        	}else if (l->getLevel() == 2){
                	l.reset(new Level1(seed));
        	}else if (l->getLevel() == 3){
                	l.reset(new Level2(seed));
        	}else if (l->getLevel() == 4){
                	l.reset(new Level3(seed));
   	     	}
	}
	if (w){
		w->fillRectangle(45+displayConst, 25, 10, 15, Xwindow::White); //clear old level
		w->drawString(46+displayConst, 35, std::to_string(getLevel()));
	}
}
void Player::printRow(int r) const{
	g->printRow(r);
}

bool Player::moveBlockLeft(int m){
	bool end = false;
	g->undraw(g->getCurrentBlock());
	end = l->moveLeft(g.get(),m,false);
	g->UpdateGrid();
	g->draw(g->getCurrentBlock());
	return end;
}

bool Player::moveBlockRight(int m){
	bool end = false;
	g->undraw(g->getCurrentBlock());
	end = l->moveRight(g.get(),m,false);
	g->UpdateGrid();
	g->draw(g->getCurrentBlock());
	return end;
}

void Player::moveBlockDown(int m){
	g->undraw(g->getCurrentBlock());
	l->moveDown(g.get(),m);
	g->UpdateGrid();
	g->draw(g->getCurrentBlock());
}

void Player::calcScore(){
	if (g->numCleared() >= 1){
                g->undrawAll();
                score = score + l->calculateScore(g.get());
                score = score + g->blockScore();
                if (w){
                        w->fillRectangle(45+displayConst, 40, 10, 15, Xwindow::White); //clear old level
                        w->drawString(46+displayConst, 55, std::to_string(getScore()));
                }
                g->drawAll();
        }
}

void Player::unHeavy(){
	g->unHeavy();
}

void Player::dropBlock(){
	g->undraw(g->getCurrentBlock());
	l->dropBlock(g.get());
	g->UpdateGrid();
	g->draw(g->getCurrentBlock());
	if (g->validDrop() == false){
		throw playerId;
	}
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
	g->drawNext();
}

void Player::notMyTurn(){
	turn = false;
}

void Player::rotateBlockClockwise(int m){
	g->undraw(g->getCurrentBlock());
	l->rotateBlockClock(g.get(),m);
	g->UpdateGrid();
	g->draw(g->getCurrentBlock());
}

void Player::rotateBlockCounterClockwise(int m){
	g->undraw(g->getCurrentBlock());
	l->rotateBlockCounterClock(g.get(),m);
	g->UpdateGrid();
	g->draw(g->getCurrentBlock());
}

void Player::noRandom(std::string file){
	if ((l->getLevel() == 3) || (l->getLevel() == 4)){
		l->noRandom(file);
	}
}

int Player::getLevel(){
	return l->getLevel();
}

void Player::Random(){
	l->Random();
}

void Player::unBlind(){
	if(g->getBlind()){
		g->unBlind();
	}
}

void Player::UpdateGrid(){
	g->UpdateGrid();
}
