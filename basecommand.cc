#include "basecommand.h"

BaseCommand::BaseCommand(){}
std::vector<std::string> BaseCommand::getCommands(std::string c){
	
	commands.clear();
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
	return commands;
}

BaseCommand::~BaseCommand(){}
