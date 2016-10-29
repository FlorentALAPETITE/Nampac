#include <MapElementFactory.hpp>
#include <Gum.hpp>
#include <Lane.hpp>
#include <Wall.hpp>

using namespace std;


shared_ptr<MapElement> MapElementFactory::createMapElement(const char type, const unsigned int c, const unsigned int l, const int sizeSprite, SDL_Renderer* renderer){
	shared_ptr<MapElement> mapElement;

	switch(type){
		case '0':
			mapElement = shared_ptr<Lane> (new Lane(c*sizeSprite,l*sizeSprite,renderer,new Gum(renderer, c*sizeSprite+9, l*sizeSprite+9)));
			break;

		case '.':
			mapElement = shared_ptr<Lane> (new Lane(c*sizeSprite,l*sizeSprite,renderer,nullptr));
			break;

		case '1':
			mapElement = shared_ptr<Wall> (new Wall(c*sizeSprite,l*sizeSprite,renderer));
			break;
	}

	return mapElement;


}