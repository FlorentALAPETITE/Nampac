#include <GhostFactory.hpp>
#include <RedGhost.hpp>
#include <BlueGhost.hpp>
#include <OrangeGhost.hpp>
#include <PinkGhost.hpp>

using namespace std;


unique_ptr<Ghost> GhostFactory::createGhost(const char type, const unsigned int c, const unsigned int l, const int sizeSprite, SDL_Renderer* renderer){
	unique_ptr<Ghost> ghost;

	switch(type){
		case 'R':
			ghost = unique_ptr<RedGhost> (new RedGhost(c*sizeSprite,l*sizeSprite,renderer));
			break;

		case 'O':
			ghost = unique_ptr<OrangeGhost> (new OrangeGhost(c*sizeSprite,l*sizeSprite,renderer));
			break;

		case 'B':
			ghost = unique_ptr<BlueGhost> (new BlueGhost(c*sizeSprite,l*sizeSprite,renderer));
			break;

		case 'P':
			ghost = unique_ptr<PinkGhost> (new PinkGhost(c*sizeSprite,l*sizeSprite,renderer));
			break;
	}

	return ghost;


}