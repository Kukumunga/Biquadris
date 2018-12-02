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



class Board;

class Biquadris {
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

public:
	// Biquadris(int,string,string,int) initalizes a game where
	// first int is the starting level
	// strings are the files each player plays from
	// seecond int the seed
	Biquadris(int,std::string,std::string,int);
	~Biquadris();
	void start();
	
};

#endif
