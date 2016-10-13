#ifndef DEF_MAPELEMENT
#define DEF_MAPELEMENT

#include <SDL2/SDL.h>


class MapElement{
	protected:
		SDL_Texture* mapElementTexture_;
		SDL_Surface* mapElementSurface_;
		SDL_Rect textureRect_;
		SDL_Renderer* renderer_;

	public:
		MapElement(char*,int,int,SDL_Renderer*);
		SDL_Rect* getTextureRect();	
		SDL_Texture* getMapElementTexture();
		virtual bool canBeCrossed()=0;
		void destroySDLElements();

};


#endif