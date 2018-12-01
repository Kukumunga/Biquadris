#include "biquadris.h"
#include "board.h"

	
			

Biquadris::Biquadris():gameBoard{std::unique_ptr<Board>(new Board())},player{1}{}
Biquadris::~Biquadris(){}
void Biquadris::start(){
try{
	std::cout << *gameBoard << std::endl;
	std::string action;	    
	while(true){
		std::vector<std::string> v;
		while(std::cin >> action){
			if (action == "exit"){
				goto endgame;
			}
			v = inter.getCommands(action);
			for(auto p:v){
				if (p == "random"){
					gameBoard->random(player);
					break;
				}
				else if (p == "norandom"){
					std::string file;
					std::cin >> file;
					gameBoard->noRandom(player,file);
					break;
				}
				else if (p == "restart"){
					gameBoard.Restart();
					player = 1;
					break;
				}
				else if(gameBoard->Move(player,p)){
					action = "drop";
					break;
				}							
			}
			std::cout << *gameBoard << std::endl;
			if(action == "drop"){
				break;
			}
		}
		//next player's turn	
		player = (player + 1)%2;	
	}
}catch(int player){
std::cout <<"Player " << player << " loses!";
goto endgame;
}
endgame:;//"goto endgame;" to end the game...
}
