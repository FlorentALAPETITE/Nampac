#ifndef DEF_SPEEDGHOSTBONUS
#define DEF_SPEEDGHOSTBONUS

#include <Bonus/Bonus.hpp>
#include <Prototype/Prototype.hpp>

using namespace std;

class SpeedGhostBonus : public Bonus, public Prototype<SpeedGhostBonus>{
public:
	SpeedGhostBonus(SDL_Renderer*,int, int);	
	SpeedGhostBonus(const SpeedGhostBonus &bonus);
	int getPoint() override;
	char getBonusType() override;
	shared_ptr<SpeedGhostBonus> clone(int,int) override;

};

#endif