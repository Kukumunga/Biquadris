#ifndef __BIQUADRIS__H
#define __BIQUADRIS__H

#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <sstream>
#include "board.h"

class Interpreter;

class Biquadris {
	Interpreter *inter;
	Board gameBoard;
	int player;

public:
	Biquadris();
	~Biquadris();
	void start();
	
};

#endif
