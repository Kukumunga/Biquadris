#include "player.h"

int Player::getScore(){
	return score;
}

int Player::getLevel(){
	return l.getLevel();
}

Player::Player(): g{Grid()} {
	g.setCurrentBlock(l->createBlock());
	nextBlock = level->createBlock();
	g.setNextBlock(nextBlock);
}


void Player::printRow(int r){
	g.printRow(r);
}

void Player::moveBlockLeft(){
	l->moveLeft(&g);
}

void Player::moveBlockRight(){
	l->moveRight(&g);
}

void Player::moveBlockDown(){
	l->moveDown(&g);
}

void Player::dropBlock(){
	l->dropBlock(&g);
}