#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <memory>
using namespace std;
#include "window.h"
#include "biquadris.h"

int main(int argc, char* argv[]) {
	string input = "";
	int level = 0;
	int c = 1;
	string f1 = "sequence1.txt";
	string f2 = "sequence2.txt";
	int seed = 1;
	bool graphics = false;
	while (c != argc){
		input = argv[c];
		if (input == "-startlevel"){
			level = std::stoi( argv[c+1]);
			c = c + 2;
		}else if(input == "-scriptfile1"){
			f1 = argv[c+1];
			c = c + 2;
		}else if(input == "-scriptfile2"){
                        f2 = argv[c+1];
                        c = c + 2;
                }else if (input == "-seed"){
			seed = std::stoi( argv[c+1]);
			c = c + 2;
		}else if (input == "-text"){
			graphics = false;
			c++;
		}
	}
	unique_ptr<Biquadris> q;
	if (graphics){
		Xwindow w;
 		q=unique_ptr<Biquadris>(new Biquadris(level,f1,f2,seed,&w));
	} else {
		q=unique_ptr<Biquadris>(new Biquadris(level,f1,f2,seed,nullptr));
	}
  	q->start();
}
