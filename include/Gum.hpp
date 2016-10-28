#ifndef DEF_GUM
#define DEF_GUM

#include <Bonus.hpp>
#include <SDL2/SDL.h>
class Gum : public Bonus
{
public:
	Gum(SDL_Renderer*,int, int);
	SDL_Rect* getTextureRect() override;
	SDL_Texture* getTexture() override;	


private:
	SDL_Texture* gumTexture_;
	SDL_Surface* gumSurface_;
	SDL_Rect gumTextureRect_;
	SDL_Renderer* renderer_;
};

#endif