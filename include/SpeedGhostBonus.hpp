#ifndef DEF_SPEEDGHOSTBONUS
#define DEF_SPEEDGHOSTBONUS

#include <Bonus.hpp>

class SpeedGhostBonus : public Bonus
{
public:
	SpeedGhostBonus(SDL_Renderer*,int, int);	
	int getPoint() override;
	char getBonusType() override;


};

#endif