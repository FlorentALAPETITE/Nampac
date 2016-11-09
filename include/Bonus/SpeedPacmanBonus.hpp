#ifndef DEF_SPEEDPACMANBONUS
#define DEF_SPEEDPACMANBONUS

#include <Bonus/Bonus.hpp>

class SpeedPacmanBonus : public Bonus
{
public:
	SpeedPacmanBonus(SDL_Renderer*,int, int);	
	int getPoint() override;
	char getBonusType() override;


};

#endif