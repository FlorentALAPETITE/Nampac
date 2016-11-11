#ifndef DEF_STUPIDGHOSTBONUS
#define DEF_STUPIDGHOSTBONUS

#include <Bonus/Bonus.hpp>

class StupidGhostBonus : public Bonus
{
public:
	StupidGhostBonus(SDL_Renderer*,int, int);	
	int getPoint() override;
	char getBonusType() override;


};

#endif