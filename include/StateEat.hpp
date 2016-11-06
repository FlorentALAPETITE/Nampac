#ifndef DEF_STATEEAT
#define DEF_STATEEAT

#ifndef DEF_STATEEAT
#define DEF_STATEEAT

#include <SDL2/SDL.h>
#include <Pacman.hpp>
#include <AGumEatState.hpp>

class StateEat: public AGumEatState
{
public:
	StateEat(Pacman* pacman, int time, int remainingTime);
	virtual void EatBonus() override;
	virtual void EndBonus() override;

private:
	Pacman* pacman_;
	int time_; 
	int remainingTime_;
};

#endif