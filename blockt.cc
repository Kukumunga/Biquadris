#include "blockt.h"
using namespace std;

BlockT::BlockT():Block("T", "red"){}
string BlockT::getType(){return Block::agetType();}
