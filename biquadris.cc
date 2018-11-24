#include "biquadris.h"

Biquadris::Biquadris():player{0}{}
Biquadris::~Biquadris(){inter = nullptr;}
void Biquadris::start(){
	std::string action;
	while(cin >> action){
		istringstream ss(action);
		int n;
		int loop = 1;
		std::vector<std::string> v;
		if (ss >> n){
			loop = n;				
		}
		while(action != "drop"){
			cin >> action;
			v = inter->getCommands(action);
			for (int i = 0; i < loop; ++loop){
				for(auto p:v){
					gameBoard.move(player,p);
				}	
			}
		}
		player = (player + 1)%2; 
	}
}