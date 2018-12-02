#include "biquadris.h"
#include "board.h"

//add sequence 
Biquadris::Biquadris(int levelStart,std::string f1,std::string f2,int seed) :gameBoard{std::unique_ptr<Board>(new Board(levelStart,f1,f2,seed))},player{1},source{&std::cin}{}
Biquadris::~Biquadris(){}

void Biquadris::start(){
try{
	std::cout << *gameBoard << std::endl;
	std::string action;	
	std::ifstream f;  
	bool stream = 0;  
	while(true){
		std::vector<std::string> moves;			
		if (source->eof()){
			if(stream == 1){
				player = (player + 1)%2;
				stream = 0;
				source = &std::cin;
			}
			else {
				goto endgame;
			}
		}
		while(*source >> action){
			if (action == "exit"){
				goto endgame;
			}
			moves = inter.getCommands(action);
			std::string move = moves[0];
			int size = moves.size();
			if (move == "sequence"){
				std::string file;
				*source >> file;
				f.open(file);
				if (f) {
					source = &f;
					stream = 1;
				}
				else {
					std::cout << "Not a valid file" << std::endl;
				}
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
				player = 0;
				std::cout << *gameBoard << std::endl;
				break;
			}
			else if(gameBoard->Move(player,move,size)){
				gameBoard->nextBlock(player);
				gameBoard->createNext(player);
				std::cout << *gameBoard << std::endl;
				break;
                        }
				std::cout << *gameBoard << std::endl;
		}
		//next player's turn
		gameBoard->newHighscore();
		player = (player + 1)%2;
		
	}
}catch(int player){
	std::cout << *gameBoard << std::endl;
	if (player == 1){
		std::cout <<"Player " << 2 << " wins!" << std::endl;
	}else{
		std::cout <<"Player " << 1 << " wins!"<< std::endl;
	}
	std::string again = "";
	std::cout << "Restart?" << std::endl;
	std::cin >> again;
	if (again == "yes"){
		gameBoard->newHighscore();
		gameBoard->Restart();
		start();
		
	}

goto endgame;
}
endgame:;//"goto endgame;" to end the game...
}
