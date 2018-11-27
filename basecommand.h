#ifndef __BASECOMMAND_H__
#define __BASECOMMAND_H__
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <sstream>
#include "interpreter.h"

class BaseCommand: public Interpreter {
protected:
	std::vector<std::string> commands;
  public:
  	BaseCommand();
    std::vector<std::string> getCommands(std::string c) override;
    ~BaseCommand();
};

#endif
