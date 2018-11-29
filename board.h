#ifndef __BOARD__H
#define __BOARD__H


#include "cell.h"
#include "player.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include <memory>

class Board{
private:
	std::unique_ptr<Player> p1;
	std::unique_ptr<Player> p2;
public:
	//~Board();
	Board();
	friend std::ostream& operator<<(std::ostream &out, const Board &b);
	void printBoards() const; // prints all the board stuff for the game
	void Move(int,std::string); // (integer, string)
	void applySpecialAction(std::string,int); 
};

std::ostream& operator<<(std::ostream &out,const  Board &b);


#endif
