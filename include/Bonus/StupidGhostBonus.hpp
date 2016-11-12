#ifndef DEF_STUPIDGHOSTBONUS
#define DEF_STUPIDGHOSTBONUS

#include <Bonus/Bonus.hpp>
#include <Prototype/Prototype.hpp>

using namespace std;

class StupidGhostBonus : public Bonus, public Prototype<StupidGhostBonus>{
public:
	StupidGhostBonus(SDL_Renderer*,int, int);	
	StupidGhostBonus(const StupidGhostBonus &bonus);
	int getPoint() override;
	char getBonusType() override;
	shared_ptr<StupidGhostBonus> clone() override;

};

#endif