#include "interpreter.h"
#include "biquadris.h"
#include "basecommand.h"
#include "board.h"
#include <string>

Biquadris::Biquadris():player{0}{}
Biquadris::~Biquadris(){inter = nullptr;}
void Biquadris::start(){
	std::string action;
	while(true){
		inter = new BaseCommand();
		//std::istringstream ss(action);
		std::vector<std::string> v;
		while(std::cin >> action){
		
			v = inter->getCommands(action);
			
			for(auto p:v){				
				gameBoard.Move(player,p);
			}
			
			if(action == "drop"){
				break;
			}
		}
		/*for(auto p:v){
			gameBoard.Move(player,p);
		}*/			
		player = (player + 1)%2;	
	}
//endgame:;//"goto endgame;" to end the game...
}
