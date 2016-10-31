#ifndef DEF_BONUS
#define DEF_BONUS

#include <SDL2/SDL.h>


class Bonus{
	public:
		Bonus(SDL_Renderer*, int, int, const char *);
		SDL_Rect* getTextureRect();
		SDL_Texture* getTexture();
		virtual int getPoint()=0;
		virtual int getBonusType()=0;

	protected:
		SDL_Texture* bonusTexture_;
		SDL_Surface* bonusSurface_;
		SDL_Rect bonusTextureRect_;
		SDL_Renderer* renderer_;

};

#endif