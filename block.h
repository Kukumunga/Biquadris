#ifndef __BLOCK__
#define __BLOCK__

class Cell;
class Coord;
class Block {
	std::vector<Cell *> components; 
	std::string type;
	std::string colour;
	int level; //level the block was created
	std::string orientation; //the block's orientation
public:
	Block();
	virtual std::string getType();
	void addCell(Cell*);
	void setLevel(int l);
	//virtual std::vector<Coord*> rotateClock();
	//virtual std::vector<Coord*> rotateCounterClock();
	//std::vector<Coord*> calcLeft();
	//std::vector<Coord*> calcRight();
	//std::vector<Coord*> calcDown();
	//void executeLeft();
	//void executeRight();
	//void executeDown();
	//virtual void executeClock();
	//virtual void executeCounterClock();
};

#endif
