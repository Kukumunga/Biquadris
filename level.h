#ifndef __LEVEL__
#define __LEVEL__

class Grid;
class Level {
public:
	virtual int getLevel()=0;
	virtual void createBlock(Grid *)=0;
	virtual void moveRight(Grid *);
	virtual void moveLeft(Grid *);
	virtual void moveDown(Grid *);
	virtual void dropBlock(Grid *);
	virtual void rotateBlockClock(Grid *);
	virtual void rotateBlockCounterClock(Grid *);
};

#endif
