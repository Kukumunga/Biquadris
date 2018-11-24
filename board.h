#ifndef __BOARD__H
#define __BOARD__H


#include "cell.h"
#include "player.h"
#include <iostream>
#include <vector>
#include <iomanip>

class Board{
private:
	Player p1;
	Player p2;
public:
	Board();
	friend std::ostream& operator<<(std::ostream &out, Board &b);
	void printBoards(); // prints all the board stuff for the game
	void Move(int,std::string) // (integer, string) 
};

std::ostream& operator<<(std::ostream &out, Board &b);


#endif