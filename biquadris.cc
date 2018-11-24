#include "interpreter.h"
#include "biquadris.h"
#include "basecommand.h"

Biquadris::Biquadris():player{0}{}
Biquadris::~Biquadris(){inter = nullptr;}
void Biquadris::start(){
	std::string action;
	while(std::cin >> action){
		inter = new BaseCommand();
		std::istringstream ss(action);
		std::vector<std::string> v;
		while(std::cin >> action){
			if(action == "drop"){
				break;
			}
			v = inter->getCommands(action);
		}
		for(auto p:v){
			gameBoard.move(player,p);
		}	
		player = (player + 1)%2; 
	}
}
