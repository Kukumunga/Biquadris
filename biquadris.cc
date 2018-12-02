#include "biquadris.h"
#include "board.h"

//add sequence 
Biquadris::Biquadris(int levelStart,std::string f1,std::string f2,int seed) :gameBoard{std::unique_ptr<Board>(new Board(levelStart,f1,f2,seed))},player{1},source{&std::cin}{}
Biquadris::~Biquadris(){}

void Biquadris::start(){
try{
	std::cout << *gameBoard << std::endl;
	// variable that gets the commands from the stream
	std::string action;	
	// stream source for sequence files
	std::ifstream f;  
	// binary varaible to tell if reading from terminal or file
	// 0 is terminal
	// 1 is file
	bool stream = 0;  
	// the last action to be called
	std::string lastaction;
	while(true){
		// to hold the vector of moves returned from the command interpreter
		std::vector<std::string> moves;			
		// if we reach the end a sequence file, 
		// we return the stream source back to the terminal
		// and let the player who called the sequence to keep playing if the last action was not drop
		// otherwise go to endgame
		if (source->eof()){
			if(stream == 1){
				stream = 0;
				source = &std::cin;
				if(lastaction == "drop"){
					// need to fix in case the play an even number of drops
					player = (player + 1)%2;
				}
			}
			else {
				goto endgame;
			}
		}
		// main loop for command interpretation
		while(*source >> action){
			if (action == "exit"){
				goto endgame;
			}
			// moves will hold a vector of commands 
			// where the size of the vector is the number of times
			// the command is done (if command is able to be repeated)
			moves = inter.getCommands(action);
			// move is the command that will be executed 
			std::string move = moves[0];
			// set lastaction to the current command
			lastaction = move;
			// number of times the command will be exectued 
			int size = moves.size();
			// reads in a file, which becomes the new stream source
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
			// reverts the board back to random
			else if (move == "random"){
				gameBoard->random(player);
			}
			// reads in a file and calls noRandom on the board
			else if (move == "norandom"){
				std::string file;
				*source >> file;
				gameBoard->noRandom(player,file);
			}
			// restarts the game and keeps track of the highscore
			else if (move == "restart"){
				gameBoard->Restart();
				player = 0;
				std::cout << *gameBoard << std::endl;
				break;
			}
			// where most board actions are done, such as moving 
			// left, right, or leveling up
			else if(gameBoard->Move(player,move,size)){
				gameBoard->nextBlock(player);
				gameBoard->createNext(player);
				std::cout << *gameBoard << std::endl;
				break;
                        }
				std::cout << *gameBoard << std::endl;
		}
		// displays highscore
		gameBoard->newHighscore();
		// next player's turn
		player = (player + 1)%2;
		
	}
	// board catches the thrown losing player 
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
