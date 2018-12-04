#include "interpreter.h"

Interpreter::Interpreter(){
	moves["drop"] = "drop";
	moves["left"] = "left";
	moves["right"] = "right";
	moves["down"] = "down";
	moves["clockwise"] = "clockwise";
	moves["counterclockwise"] = "counterclockwise";
	moves["levelup"] = "levelup";
	moves["leveldown"] = "leveldown";
	moves["sequence"] = "sequence";
	moves["I"] = "I";
	moves["J"] = "J";
	moves["L"] = "L";
	moves["O"] = "O";
	moves["S"] = "S";
	moves["Z"] = "Z";
	moves["T"] = "T";
}
void Interpreter::autocomplete(){
	int n = 0;
	int size = commands.size();
	std::string move = commands[0];
	std::string action;
	for (auto &p:moves){
		if(p.first == move){
			n = 1;
			action = p.second;
			break;
		}
		if (p.second != p.first) {
			if(p.second == move) {
				action = "";
				n = 1;
				break;
			}
		}
		if(p.first.substr(0,move.length()) == move){
			action = p.second;
			n++;
		}
	}
	if (n == 1){
		for (int i = 0; i < size; ++i){
			commands[i] = action;
 		}
	}
}
void Interpreter::multiplier(std::string c){
	std::string number;
	int n;
	int size = c.size();
	std::string command;
	for(int i = 0; i < size; ++i) {
		std::string test;
		test.push_back(c[i]);
    	std::istringstream ss(test);
    	if(ss >> n){
    		number+=test;
    	}
    	else {
    		if(number.size() > 0){
    			std::istringstream ss(number);
    			ss >> n;
				command = c.substr(i);
    		}
    		else {
    			command = c;
    			n = 1;
    		}    		
    		break;
    	}
	}
	for(int i = 0; i < n; ++i){
		commands.emplace_back(command);
	}
}
std::vector<std::string> Interpreter::getCommands(std::string c){
	commands.clear();
	multiplier(c);
	autocomplete();
	return commands;
}
void Interpreter::rename(std::string oldc,std::string newc){
	for(auto move:special){
		if (move == newc){
			std::cout << "Cannot change this command" << std::endl;
			return;
		}
	}
	std::map<std::string,std::string>::iterator it;
	it = moves.find(newc);
	if(it != moves.end()){
		std::cout << newc << " is already a command" << std::endl;
		return;
	}
	it = moves.find(oldc);
	if(it != moves.end()){
		std::cout << oldc << " is now " << newc << std::endl;
		moves[newc] = moves[oldc];
		moves.erase(it);
	}
}
Interpreter::~Interpreter(){}
