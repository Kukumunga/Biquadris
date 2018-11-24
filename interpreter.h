#ifndef __INTERPRETER_H__
#define __INTERPRETER_H__
#include <iostream>
#include <string>
#include <vector>

class Interpreter {
  public:
    virtual std::vector<std::string> getCommands(std::string c) = 0;
    virtual ~Interpreter();
};

#endif
