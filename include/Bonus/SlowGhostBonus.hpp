#ifndef DEF_SLOWGHOSTBONUS
#define DEF_SLOWGHOSTBONUS

#include <Bonus/Bonus.hpp>
#include <Prototype/Prototype.hpp>

using namespace std;

class SlowGhostBonus : public Bonus, public Prototype<SlowGhostBonus>{
public:
	SlowGhostBonus(SDL_Renderer*,int, int);	
	SlowGhostBonus(const SlowGhostBonus &bonus);
	int getPoint() override;
	char getBonusType() override;
	shared_ptr<SlowGhostBonus> clone() override;

};

#endif