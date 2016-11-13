#ifndef DEF_MAPELEMENTFACTORY
#define DEF_MAPELEMENTFACTORY

#include <MapElement/MapElement.hpp>
#include <memory>
#include <SDL2/SDL.h>
#include <Prototype/BonusFactory.hpp>
#include <MapElement/Lane.hpp>
#include <MapElement/Wall.hpp>


using namespace std;

class MapElementFactory {

	public:
		MapElementFactory(const int sizeSprite, SDL_Renderer* renderer);
		virtual shared_ptr<MapElement> createMapElement(const char type, const unsigned int c, const unsigned int  l, int& gumNumber);

	protected:
		unique_ptr<BonusFactory> bonusFactory_;

		shared_ptr<Lane> lanePrototype_;
		shared_ptr<Wall> wallPrototype_;
		int sizeSprite_;

};


#endif