#ifndef DEF_SLOWGHOSTBONUS
#define DEF_SLOWGHOSTBONUS

#include <Bonus.hpp>
#include <SDL2/SDL.h>
class SlowGhostBonus : public Bonus
{
public:
	SlowGhostBonus(SDL_Renderer*,int, int);	
	int getPoint() override;
	int getBonusType();


};

#endif