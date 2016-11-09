#include <MapElementFactory.hpp>
#include <Lane.hpp>
#include <Wall.hpp>

using namespace std;


MapElementFactory::MapElementFactory():MapFactory(){

}


shared_ptr<MapElement> MapElementFactory::createMapElement(const char type, const unsigned int c, const unsigned int l, const int sizeSprite, SDL_Renderer* renderer,int &gumNumber){
	shared_ptr<MapElement> mapElement;

	if (type == '1')
		mapElement = shared_ptr<Wall> (new Wall(c*sizeSprite,l*sizeSprite,renderer));
	

	else{
		shared_ptr<Bonus> bonus = bonusFactory_->createBonus(type, c,l,sizeSprite,renderer, gumNumber);
		mapElement = shared_ptr<Lane> (new Lane(c*sizeSprite,l*sizeSprite,renderer,bonus));
	}		


	return mapElement;


}