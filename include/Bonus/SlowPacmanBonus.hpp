#ifndef DEF_SLOWPACMANBONUS
#define DEF_SLOWPACMANBONUS

#include <Bonus/Bonus.hpp>
#include <Prototype/Prototype.hpp>

using namespace std;

class SlowPacmanBonus : public Bonus,  public Prototype<SlowPacmanBonus>{
public:
	SlowPacmanBonus(SDL_Renderer*,int, int);	
	SlowPacmanBonus(const SlowPacmanBonus &bonus);
	int getPoint() override;
	char getBonusType() override;
	shared_ptr<SlowPacmanBonus> clone() override;


};

#endif