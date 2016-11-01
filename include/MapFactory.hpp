#ifndef DEF_MAPFACTORY
#define DEF_MAPFACTORY

#include <MapElement.hpp>
#include <memory>
#include <SDL2/SDL.h>
#include <BonusFactory.hpp>

using namespace std;

class MapFactory {

	public:
		MapFactory();
		virtual shared_ptr<MapElement> createMapElement(const char type, const unsigned int c, const unsigned int  l, const int sizeSprite, SDL_Renderer* renderer) = 0;

	protected:
		unique_ptr<BonusFactory> bonusFactory_;

};


#endif