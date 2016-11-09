#ifndef DEF_GHOSTFACTORY
#define DEF_GHOSTFACTORY

#include <Character/Character.hpp>
#include <memory>
#include <SDL2/SDL.h>

using namespace std;

class GhostFactory {

	public:
		virtual shared_ptr<Character> createGhost(const char type, const unsigned int c, const unsigned int  l, const int sizeSprite, SDL_Renderer* renderer) = 0;


};


#endif