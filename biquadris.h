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
	Interpreter inter;
	std::unique_ptr<Board> gameBoard;
	int player;
	std::istream *source;

public:
	Biquadris();
	~Biquadris();
	void start();
	
};

#endif
