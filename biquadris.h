#ifndef __BIQUADRIS__H
#define __BIQUADRIS__H

#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include "board.h"

class Interpreter;

class biquadris {
	Interpreter *inter;
	Board gameBoard;
	int player;

public:
	biquadris();
	~biquadris();
	void start();
	
};
