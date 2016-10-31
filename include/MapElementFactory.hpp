#ifndef DEF_MAPELEMENTFACTORY
#define DEF_MAPELEMENTFACTORY

#include <MapFactory.hpp>

using namespace std;

class MapElementFactory : public MapFactory{

	public:
		MapElementFactory();
		shared_ptr<MapElement> createMapElement(const char type, const unsigned int c, const unsigned int l, const int sizeSprite, SDL_Renderer* renderer) override;


};


#endif