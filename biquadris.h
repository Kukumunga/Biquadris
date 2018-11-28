#ifndef __BIQUADRIS__H
#define __BIQUADRIS__H

#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <sstream>
#include "board.h"
#include <memory>

class Interpreter;

class Biquadris {
	Interpreter *inter;
	std::unique_ptr<Board> gameBoard;
	int player;

public:
	Biquadris();
	~Biquadris();
	void start();
	
};

#endif
