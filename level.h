#ifndef __LEVEL__
#define __LEVEL__

class Grid;
class Level {
public:
	virtual ~Level()=0;
	virtual int getLevel()=0;
	virtual void createBlock(Grid *)=0;
	virtual void moveRight(Grid *);
	virtual void moveLeft(Grid *);
	virtual bool moveDown(Grid *);
	virtual void dropBlock(Grid *);
	virtual void rotateBlockClock(Grid *);
	virtual void rotateBlockCounterClock(Grid *);
};

#endif
