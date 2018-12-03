#ifndef __BIQUADRIS__H
#define __BIQUADRIS__H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include "interpreter.h"
#include <memory>


class Xwindow;
class Board;

class Biquadris {
	Xwindow *w; //to pass on to board
	bool createwin;

	// an interpreter that takes in user input and interprets it to something actionable 
	Interpreter inter;
	// has a game board 
	std::unique_ptr<Board> gameBoard;
	// keeps track of the current player 
	int player;
	// inital start level
	int startLevel=0;
	// a stream source to take in commands
	std::istream *source;
	int bonus;
	void gameOver();
public:
	//Biquadris(int,std::string,std::string,int,bool);// initalizes a game where
	// first int is the starting level
	// strings are the files each player plays from
	// seecond int the seed
	Biquadris(int,std::string,std::string,int, Xwindow*, int);
	~Biquadris();
	void start();
	
};

#endif
