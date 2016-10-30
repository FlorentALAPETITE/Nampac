#include <GhostFactory.hpp>
#include <RedGhost.hpp>
#include <BlueGhost.hpp>
#include <OrangeGhost.hpp>
#include <PinkGhost.hpp>

using namespace std;


shared_ptr<Character> GhostFactory::createGhost(const char type, const unsigned int c, const unsigned int l, const int sizeSprite, SDL_Renderer* renderer){
	shared_ptr<Character> ghost;

	switch(type){
		case 'R':
			ghost = shared_ptr<Character>(new RedGhost(c*sizeSprite,l*sizeSprite,renderer));
			break;

		case 'O':
			ghost = shared_ptr<Character>(new OrangeGhost(c*sizeSprite,l*sizeSprite,renderer));
			break;

		case 'B':
			ghost = shared_ptr<Character>(new BlueGhost(c*sizeSprite,l*sizeSprite,renderer));
			break;

		case 'P':
			ghost = shared_ptr<Character>(new PinkGhost(c*sizeSprite,l*sizeSprite,renderer));
			break;
	}

	return ghost;


}