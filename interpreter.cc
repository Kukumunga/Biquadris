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
	//fix invalid commands
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

Interpreter::~Interpreter(){}
