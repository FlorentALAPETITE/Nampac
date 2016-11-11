#ifndef DEF_CONCRETEBONUSFACTORY
#define DEF_CONCRETEBONUSFACTORY

#include <Prototype/BonusFactory.hpp>
#include <memory>
#include <SDL2/SDL.h>

using namespace std;

class ConcreteBonusFactory : public BonusFactory {

	public:
		shared_ptr<Bonus> createBonus(const char type, const unsigned int c, const unsigned int  l, const int sizeSprite, SDL_Renderer* renderer,int &gumNumber) override;


};


#endif