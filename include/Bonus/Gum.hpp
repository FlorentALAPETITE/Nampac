#ifndef DEF_GUM
#define DEF_GUM

#include <Bonus/Bonus.hpp>
#include <SDL2/SDL.h>
#include <Prototype/Prototype.hpp>

using namespace std;


class Gum : public Bonus , public Prototype<Gum>{
public:
	Gum(SDL_Renderer*,int, int);	
	Gum(const Gum &bonus);
	int getPoint() override;
	char getBonusType() override;
	shared_ptr<Gum> clone(int,int) override;

};

#endif