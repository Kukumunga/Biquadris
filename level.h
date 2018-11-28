#ifndef __LEVEL__
#define __LEVEL__

class Grid;
class Level {
public:
	virtual ~Level()=0;
	virtual int getLevel()=0;
	virtual void createBlock(Grid *)=0;
	virtual void moveRight(Grid *)=0;
	virtual void moveLeft(Grid *)=0;
	virtual bool moveDown(Grid *)=0;
	virtual void dropBlock(Grid *)=0;
	virtual void rotateBlockClock(Grid *)=0;
	virtual void rotateBlockCounterClock(Grid *)=0;
};

#endif
