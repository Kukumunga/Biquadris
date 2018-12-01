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
		std::vector<std::string> moves;
		while(std::cin >> action){
			if (action == "exit"){
				goto endgame;
			}
			moves = inter.getCommands(action);
			std::string move = moves[0];
			int size = moves.size();
			if (move == "random"){
				gameBoard->random(player);
			}
			else if (move == "norandom"){
				std::string file;
				std::cin >> file;
				gameBoard->noRandom(player,file);
			}
			else if (move == "restart"){
				gameBoard->Restart();
				player = 1;
				std::cout << *gameBoard << std::endl;
				break;
			}
			else if(gameBoard->Move(player,move,size)){
				std::cout << *gameBoard << std::endl;
				break;
			}
			std::cout << *gameBoard << std::endl;
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
