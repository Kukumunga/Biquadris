#include "player.h"

int Player::getScore(){
	//return score;
	return 1;
}

int Player::getLevel(){
	//return l.getLevel()
	return 1;
}

Player::Player(): g{Grid()},l{Level0("hello")}{
	 l.createBlock(g);
}

void Player::printRow(int r){
	g.printRow(r);
}

void Player::moveBlockLeft(){
	//l->moveLeft(&g);
}

void Player::moveBlockRight(){
	//l->moveRight(&g);
}

void Player::moveBlockDown(){
	//l->moveDown(&g);
}

void Player::dropBlock(){
	//l->dropBlock(&g);
	//g.addToCurrent(); //  add the current block in grid to the list of vectors
	//g.updateGrid();  update then check for removal?
	//g.nextBlock(); // sets currentBlock = NextBlock
}
