#include "basecommand.h"

BaseCommand::BaseCommand(){}
std::vector<std::string> BaseCommand::getCommands(std::string c){
	
	commands.clear();
	commands.emplace_back(c);
	
	return commands;
}

BaseCommand::~BaseCommand(){}
