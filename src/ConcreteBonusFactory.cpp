#include <ConcreteBonusFactory.hpp>
#include <Gum.hpp>
#include <SlowGhostBonus.hpp>

using namespace std;



shared_ptr<Bonus> ConcreteBonusFactory::createBonus(const char type, const unsigned int c, const unsigned int l, const int sizeSprite, SDL_Renderer* renderer){
	shared_ptr<Bonus> bonus;

	switch(type){
		case '0':
			bonus = shared_ptr<Gum> (new Gum(renderer, c*sizeSprite+9, l*sizeSprite+9));
			break;

		case '.':
			bonus = nullptr;
			break;

		case '~':
			bonus = shared_ptr<SlowGhostBonus> (new SlowGhostBonus(renderer, c*sizeSprite+9, l*sizeSprite+9));

	}

	return bonus;


}