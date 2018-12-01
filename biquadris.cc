#include "biquadris.h"
#include "board.h"

//add sequence 
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
			for(auto move:v){
				int size = commands.size();
				if (move == "random"){
					gameBoard->random(player);
					break;
				}
				else if (move == "norandom"){
					std::string file;
					std::cin >> file;
					gameBoard->noRandom(player,file);
					break;
				}
				else if (move == "restart"){
					gameBoard.Restart();
					player = 1;
					break;
				}
				else if(gameBoard->Move(player,move,size)){
					action = "drop";
					break;
				}
				else {
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
