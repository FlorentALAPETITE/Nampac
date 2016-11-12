#ifndef DEF_SPEEDPACMANBONUS
#define DEF_SPEEDPACMANBONUS

#include <Bonus/Bonus.hpp>
#include <Prototype/Prototype.hpp>

using namespace std;

class SpeedPacmanBonus : public Bonus, public Prototype<SpeedPacmanBonus>{
public:
	SpeedPacmanBonus(SDL_Renderer*,int, int);	
	SpeedPacmanBonus(const SpeedPacmanBonus &bonus);
	int getPoint() override;
	char getBonusType() override;
	shared_ptr<SpeedPacmanBonus> clone() override;

};

#endif