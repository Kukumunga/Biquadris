#include "interpreter.h"
#include "biquadris.h"
#include "basecommand.h"
#include "board.h"
#include <string>

Biquadris::Biquadris():player{1}{}
Biquadris::~Biquadris(){delete inter;}
void Biquadris::start(){
	std::cout << gameBoard << std::endl;
	std::string action;
	while(true){
		inter = new BaseCommand();//heap allocated
		//std::istringstream ss(action);
		std::vector<std::string> v;
		while(std::cin >> action){
		
			v = inter->getCommands(action);
			
			for(auto p:v){				
				gameBoard.Move(player,p);
				action = p;
			}
			std::cout << gameBoard << std::endl;
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
