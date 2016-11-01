#ifndef DEF_GUM
#define DEF_GUM

#include <Bonus.hpp>
#include <SDL2/SDL.h>
class Gum : public Bonus
{
public:
	Gum(SDL_Renderer*,int, int);	
	int getPoint() override;
	char getBonusType() override;


};

#endif