#include "blockt.h"
using namespace std;

BlockT::BlockT():Block("t", "red"){}
string BlockT::getType(){return Block::agetType();}
