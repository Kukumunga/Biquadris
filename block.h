#ifndef __BLOCK__
#define __BLOCK__
#include <vector>
#include <string>

class Cell;
class Coord;
class Block {
protected:
	
	std::vector<Coord> components; 
	std::string type;
	std::string colour;
	int level; //level the block was created
	std::string orientation; //the block's orientation
public:
	~Block();
	void undraw();
	int compSize(){return components.size();}
	Block(std::string type, std::string colour);
	std::string agetType();
	std::string getColour(){return colour;}
	std::vector<Coord> getComp();
	void addCoord(Coord);
	void setLevel(int l);
	void removeComp(int position);
	void lowerY(int position);
	bool isComponent(Coord component); //checks whether the component is in components
	virtual std::vector<Coord> rotateClock()=0;
	virtual std::vector<Coord> rotateCounterClock()=0;
	std::vector<Coord> calcLeft();
	std::vector<Coord> calcRight();
	std::vector<Coord> calcDown();
	void executeLeft();
	void executeRight();
	void executeDown();
	virtual void executeClock()=0;
	virtual void executeCounterClock()=0;
	int getLevel();
};

#endif
