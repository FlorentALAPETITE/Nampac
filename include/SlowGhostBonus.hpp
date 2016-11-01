#ifndef DEF_SLOWGHOSTBONUS
#define DEF_SLOWGHOSTBONUS

#include <Bonus.hpp>

class SlowGhostBonus : public Bonus
{
public:
	SlowGhostBonus(SDL_Renderer*,int, int);	
	int getPoint() override;
	char getBonusType();


};

#endif