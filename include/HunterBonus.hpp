#ifndef DEF_HUNTERBONUS
#define DEF_HUNTERBONUS

#include <Bonus.hpp>

class HunterBonus : public Bonus
{
public:
	HunterBonus(SDL_Renderer*,int, int);	
	int getPoint() override;
	char getBonusType();


};

#endif