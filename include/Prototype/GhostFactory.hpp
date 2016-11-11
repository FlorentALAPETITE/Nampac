#ifndef DEF_GHOSTFACTORY
#define DEF_GHOSTFACTORY

#include <Character/RedGhost.hpp>
#include <Character/BlueGhost.hpp>
#include <Character/OrangeGhost.hpp>
#include <Character/PinkGhost.hpp>
#include <memory>
#include <SDL2/SDL.h>

using namespace std;

class GhostFactory {

	public:
		GhostFactory(const int sizeSprite, SDL_Renderer* renderer);
		shared_ptr<Ghost> createGhost(const char type, const unsigned int c, const unsigned int  l);

	private:
		shared_ptr<BlueGhost> blueGhostPrototype_;
		shared_ptr<OrangeGhost> orangeGhostPrototype_;
		shared_ptr<RedGhost> redGhostPrototype_;
		shared_ptr<PinkGhost> pinkGhostPrototype_;

		int sizeSprite_;

};


#endif