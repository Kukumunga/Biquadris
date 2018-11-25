#ifndef __BLOCK__
#define __BLOCK__
#include <vector>
#include <string>

class Cell;
class Coord;
class Block {
protected:
	std::vector<Cell *> components; 
	std::string type;
	std::string colour;
	int level; //level the block was created
	std::string orientation; //the block's orientation
public:
	~Block();
	Block(std::string type, std::string colour);
	std::string agetType();
	void addCell(Cell*);
	void setLevel(int l);
	//virtual std::vector<Coord*> rotateClock();
	//virtual std::vector<Coord*> rotateCounterClock();
	std::vector<Coord*> calcLeft();
	std::vector<Coord*> calcRight();
	std::vector<Coord*> calcDown();
	//void executeLeft();
	//void executeRight();
	//void executeDown();
	//virtual void executeClock();
	//virtual void executeCounterClock();
};

#endif
