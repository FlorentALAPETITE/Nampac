#ifndef DEF_STATENOTEAT
#define DEF_STATENOTEAT

#include <SDL2/SDL.h>
#include <Pacman.hpp>
#include <AGumEatState.hpp>

class StateNotEat: public AGumEatState
{
public:
	StateNotEat(Pacman* pacman, int time, int remainingTime);
	virtual void EatBonus() override;
	virtual void EndBonus() override;
	
private:	
	Pacman* pacman_;
	int time_; 
	int remainingTime_;

};

#endif