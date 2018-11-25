#include "player.h"

int Player::getScore(){
	//return score;
	return 1;
}

int Player::getLevel(){
//	return l.getLevel()
	return 1;
}

Player::Player(): g{Grid()},l{Level0("hello")}{
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
	//g.addToCurrent(); //  add the current block in grid to the list of vectors
	g.UpdateGrid();  //update then check for removal?
	//g.nextBlock(); // sets currentBlock = NextBlock
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