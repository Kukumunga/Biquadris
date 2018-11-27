#include "player.h"

int Player::getScore(){
	//return score;
	return 1;
}

int Player::getLevel(){
//	return l.getLevel()
	return 1;
}

Player::Player(): g{Grid()},l{Level0("sequence1.txt")}{
	l.createBlock(&g);
	g.next();
	g.UpdateGrid();
	l.createBlock(&g);
}

void Player::printRow(int r){
	g.printRow(r);
}

void Player::moveBlockLeft(){
	l.moveLeft(&g);
	g.UpdateGrid();
}

void Player::moveBlockRight(){
	l.moveRight(&g);
	g.UpdateGrid();
}

void Player::moveBlockDown(){
	l.moveDown(&g);
	g.UpdateGrid();
}

void Player::dropBlock(){
	l.dropBlock(&g);
	g.UpdateGrid();
	g.clearFullRows();
	g.next();
	g.UpdateGrid();
	l.createBlock(&g);
	  
}

void Player::printNextBlock(int line){
	if (turn){
		g.printNextBlock(line);
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
	l.rotateBlockClock(&g);
}

void Player::rotateBlockCounterClockwise(){
	l.rotateBlockCounterClock(&g);
}
