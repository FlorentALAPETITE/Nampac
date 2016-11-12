#ifndef DEF_HUNTERBONUS
#define DEF_HUNTERBONUS

#include <Bonus/Bonus.hpp>
#include <Prototype/Prototype.hpp>

using namespace std;

class HunterBonus : public Bonus, public Prototype<HunterBonus>{
public:
	HunterBonus(SDL_Renderer*,int, int);	
	HunterBonus(const HunterBonus &bonus);
	int getPoint() override;
	char getBonusType() override;
	shared_ptr<HunterBonus> clone() override;

};

#endif