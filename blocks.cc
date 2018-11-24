#include "blocks.h"
using namespace std;

BlockS::BlockS():Block("s", "yellow"){}
string BlockS::getType(){return Block::agetType();}
