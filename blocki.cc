#include "blocki.h"
using namespace std;

BlockI::BlockI():Block("i", "green"){}

string BlockI::getType(){
	return Block::getType();
}

string BlockI::getType(){return type;}
