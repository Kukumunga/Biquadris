#ifndef __LEVEL__
#define __LEVEL__
#include <string>
class Grid;
class Level {
protected:
	int level = 0;
public:
	Level();
	virtual ~Level()=0;
	virtual int getLevel()=0;
	virtual void createBlock(Grid *)=0;
	virtual bool moveRight(Grid *); //returns whether the turn should end (used 4 heavy)
	virtual bool moveLeft(Grid *); //returns whether the turn should end (used 4 heavy)
	virtual bool moveDown(Grid *); //returns whether it can move down (used in drop)
	virtual void dropBlock(Grid *);
	virtual void rotateBlockClock(Grid *);
	virtual void rotateBlockCounterClock(Grid *);
	virtual int  calculateScore(Grid *)=0 ;
//	void noRandom(std::string)=0;
//	void Random() =0 ;
};

#endif
