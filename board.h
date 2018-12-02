#ifndef __BOARD__H
#define __BOARD__H


#include "cell.h"
#include "player.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include <memory>
#include <string>
class Board{
private:
	std::unique_ptr<Player> p1;
	std::unique_ptr<Player> p2;
	int highscore;
public:
	//~Board();
	Board(int);
	friend std::ostream& operator<<(std::ostream &out, const Board &b);
	void printBoards() const; // prints all the board stuff for the game
	bool Move(int,std::string,int); // (integer, string)
	void applySpecialAction(std::string,int);
	//std::shared_ptr<Xwindow> xw;
	void noRandom(int,std::string); 
	void random(int);
	void Restart();
	void nextBlock(int);
	void createNext(int);
	int getHighscore()const;
	void newHighscore();
};

std::ostream& operator<<(std::ostream &out,const  Board &b);


#endif
