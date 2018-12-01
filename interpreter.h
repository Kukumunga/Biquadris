#ifndef __INTERPRETER_H__
#define __INTERPRETER_H__
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>

class Interpreter {
private:
	std::vector<std::string> commands;
    std::map<std::string, std::string> moves;
	void multiplier(std::string command, int n);
	void autocomplete();
  public:
  	Interpreter();
    std::vector<std::string> getCommands(std::string c);
    ~Interpreter();
};

#endif
