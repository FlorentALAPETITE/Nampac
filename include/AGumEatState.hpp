#ifndef DEF_AGUMEATSTATE
#define DEF_AGUMEATSTATE

#include <SDL2/SDL.h>

class AGumEatState
{
public:
	AGumEatState(Pacman* pacman, int time, int remainingTime);
	virtual void EatBonus() = 0;
	virtual void EndBonus() = 0;
	int getTime();
	int getRemainingTime();

private:
	Pacman* pacman_;
	int time_; 
	int remainingTime_;

};

#endif