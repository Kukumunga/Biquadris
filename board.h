#ifndef __BOARD__H
#define __BOARD__H

#include "player.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include <memory>
#include <string>
class Board{
private:
	Xwindow *w;
	std::unique_ptr<Player> p1;
	std::unique_ptr<Player> p2;
	int highscore=0;
public:
	void initWindow(); //initialize the window when game begins
	Board(int,std::string,std::string,int,Xwindow *);
	friend std::ostream& operator<<(std::ostream &out, const Board &b);
	void printBoards() const; // prints all the board stuff for the game
	bool Move(int,std::string,int); 
	void applySpecialAction(std::string,int);
	void noRandom(int,std::string); 
	void random(int);
	void Restart();
	void nextBlock(int);
	void createNext(int);
	int getHighscore()const;
	void newHighscore();
	void clearRows(int);
	void UpdateGrid(int);
	void applySpecial(int);
	void calcScore(int);
	void unBlind(int);
	void unHeavy(int);
};

std::ostream& operator<<(std::ostream &out,const  Board &b);


#endif
