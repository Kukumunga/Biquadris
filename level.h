#ifndef __LEVEL__
#define __LEVEL__

class Grid;
class Level {
public:
	int virtual getLevel()=0;
	void virtual createBlock(Grid *)=0;
	void virtual moveRight(Grid *);
	void virtual moveLeft(Grid *);
	void virtual moveDown(Grid *);
	void virtual dropBlock(Grid *);
	void virtual rotateBlockClock(Grid *);
	void virtual rotateBlockCounterClock(Grid *);
};

#endif
