#include "biquadris.h"
#include "board.h"

//add sequence 
Biquadris::Biquadris():gameBoard{std::unique_ptr<Board>(new Board())},player{1},source{&std::cin}{}
Biquadris::~Biquadris(){}
void Biquadris::start(){
try{
	std::cout << *gameBoard << std::endl;
	std::string action;	
	std::ifstream f;    
	while(true){
		bool stream = 0;
		std::vector<std::string> moves;
		while(*source >> action){
			if (action == "exit"){
				goto endgame;
			}
			moves = inter.getCommands(action);
			std::string move = moves[0];
			int size = moves.size();
			if (source->eof()){
				std::cout << "here" << std::endl;
				if(stream == 1){
					stream = 0;
					source = &std::cin;
				}
				else {
					goto endgame;
				}
			}
			else if (move == "sequence"){
				std::string file;
				*source >> file;
				f.open(file);
				source = &f;
				*source >> file;
				stream = 1;
			}
			else if (move == "random"){
				gameBoard->random(player);
			}
			else if (move == "norandom"){
				std::string file;
				*source >> file;
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
		gameBoard->nextBlock(player);
		player = (player + 1)%2;

	}
}catch(int player){
std::cout <<"Player " << player << " loses!";
goto endgame;
}
endgame:;//"goto endgame;" to end the game...
}
