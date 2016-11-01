#ifndef DEF_SLOWPACMANBONUS
#define DEF_SLOWPACMANBONUS

#include <Bonus.hpp>

class SlowPacmanBonus : public Bonus
{
public:
	SlowPacmanBonus(SDL_Renderer*,int, int);	
	int getPoint() override;
	char getBonusType();


};

#endif