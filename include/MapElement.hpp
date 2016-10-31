#ifndef DEF_MAPELEMENT
#define DEF_MAPELEMENT

#include <SDL2/SDL.h>
#include <Bonus.hpp>
#include <memory>

using namespace std;

class MapElement{
	protected:
		SDL_Texture* mapElementTexture_;
		SDL_Surface* mapElementSurface_;
		SDL_Rect textureRect_;
		SDL_Renderer* renderer_;			
		shared_ptr<Bonus> bonus_;

	public:
		MapElement(char*,int,int,SDL_Renderer*,shared_ptr<Bonus> b);
		SDL_Rect* getTextureRect();	
		SDL_Texture* getMapElementTexture();
		virtual bool canBeCrossed()=0;
		void destroySDLElements();
		shared_ptr<Bonus> getBonus();
		void eatBonus();

};


#endif