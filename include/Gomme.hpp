#ifndef DEF_GOMME
#define DEF_GOMME

#include <Bonus.hpp>
#include <SDL2/SDL.h>
class Gomme : public Bonus
{
public:
	Gomme(SDL_Renderer*);
	SDL_Rect* getTextureRect() override;
	SDL_Texture* getTexture() override;
	void setBonusTextureRect(int x, int y) override;


private:
	SDL_Texture* GommeTexture_;
	SDL_Surface* GommeSurface_;
	SDL_Rect GommeTextureRect_;
	SDL_Renderer* renderer_;
};

#endif