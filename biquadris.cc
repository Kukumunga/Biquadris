#include "interpreter.h"
#include "biquadris.h"
#include "basecommand.h"
#include "board.h"
#include <string>
#include <memory>

Biquadris::Biquadris():gameBoard{std::unique_ptr<Board>(new Board())},player{1}{}
Biquadris::~Biquadris(){delete inter;}
void Biquadris::start(){
try{
	std::cout << *gameBoard << std::endl;
	std::string action;
	while(true){
		std::unique_ptr<BaseCommand>inter{new BaseCommand()};//heap allocated
		//std::istringstream ss(action);
		std::vector<std::string> v;
		while(std::cin >> action){
			if (action == "exit"){
				goto endgame;
			}	
			v = inter->getCommands(action);
			
			for(auto p:v){				
				gameBoard->Move(player,p);
				action = p;
			}
			std::cout << *gameBoard << std::endl;
			if(action == "drop"){
				break;
			}
		}
		/*for(auto p:v){
			gameBoard.Move(player,p);
		}*/			
		player = (player + 1)%2;	
	}
}catch(int player){
std::cout <<"Player " << player << " loses!";
goto endgame;
}
endgame:;//"goto endgame;" to end the game...
}
