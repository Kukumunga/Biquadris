#include "blocki.h"
using namespace std;

BlockI::BlockI():Block("I", "green"){}

string BlockI::getType(){
	return Block::agetType();
}


