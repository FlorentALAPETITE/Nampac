#include <ConcreteBonusFactory.hpp>
#include <Gum.hpp>
#include <SlowGhostBonus.hpp>
#include <SpeedGhostBonus.hpp>
#include <SlowPacmanBonus.hpp>
#include <SpeedPacmanBonus.hpp>

using namespace std;



shared_ptr<Bonus> ConcreteBonusFactory::createBonus(const char type, const unsigned int c, const unsigned int l, const int sizeSprite, SDL_Renderer* renderer){
	shared_ptr<Bonus> bonus;

	switch(type){
		case '0':
			bonus = shared_ptr<Gum> (new Gum(renderer, c*sizeSprite+8, l*sizeSprite+8));
			break;

		case '.':
			bonus = nullptr;
			break;

		case '~':
			bonus = shared_ptr<SlowGhostBonus> (new SlowGhostBonus(renderer, c*sizeSprite+3, l*sizeSprite+3));
			break;

		case '#':
			bonus = shared_ptr<SpeedGhostBonus> (new SpeedGhostBonus(renderer, c*sizeSprite+3, l*sizeSprite+3));
			break;

		case '+':
			bonus = shared_ptr<SpeedPacmanBonus> (new SpeedPacmanBonus(renderer, c*sizeSprite+3, l*sizeSprite+3));
			break;

		case '-':
			bonus = shared_ptr<SlowPacmanBonus> (new SlowPacmanBonus(renderer, c*sizeSprite+3, l*sizeSprite+3));
			break;

	}

	return bonus;


}