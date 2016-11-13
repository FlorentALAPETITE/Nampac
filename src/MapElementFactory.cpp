#include <Prototype/MapElementFactory.hpp>

using namespace std;


MapElementFactory::MapElementFactory(const int sizeSprite, SDL_Renderer* renderer):sizeSprite_(sizeSprite){
	bonusFactory_ = unique_ptr<BonusFactory>(new BonusFactory(sizeSprite_,renderer));
	wallPrototype_ = shared_ptr<Wall> (new Wall(0, 0,renderer));
	lanePrototype_ = shared_ptr<Lane> (new Lane(0, 0,renderer));
}


shared_ptr<MapElement> MapElementFactory::createMapElement(const char type, const unsigned int c, const unsigned int l, int &gumNumber){
	shared_ptr<MapElement> mapElement;

	if (type == '1')
		mapElement = wallPrototype_->clone(c*sizeSprite_,l*sizeSprite_);
	

	else{
		shared_ptr<Bonus> bonus = bonusFactory_->createBonus(type, c,l, gumNumber);
		mapElement = lanePrototype_->clone(c*sizeSprite_,l*sizeSprite_);
		mapElement->setBonus(bonus);
	}		


	return mapElement;


}