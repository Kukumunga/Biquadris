#include "blocko.h"
using namespace std;

BlockO::BlockO():Block("O", "blue"){}
string BlockO::getType(){return Block::agetType();}
