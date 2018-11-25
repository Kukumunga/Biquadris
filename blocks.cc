#include "blocks.h"
using namespace std;

BlockS::BlockS():Block("S", "yellow"){}
string BlockS::getType(){return Block::agetType();}
