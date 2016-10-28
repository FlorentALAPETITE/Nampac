#ifndef DEF_BONUS
#define DEF_BONUS

#include <SDL2/SDL.h>

class Bonus{
	public:
		virtual SDL_Rect* getTextureRect() = 0;	
		virtual SDL_Texture* getTexture() = 0;	
};

#endif