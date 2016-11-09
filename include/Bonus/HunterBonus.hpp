#ifndef DEF_HUNTERBONUS
#define DEF_HUNTERBONUS

#include <Bonus/Bonus.hpp>

class HunterBonus : public Bonus
{
public:
	HunterBonus(SDL_Renderer*,int, int);	
	int getPoint() override;
	char getBonusType() override;


};

#endif