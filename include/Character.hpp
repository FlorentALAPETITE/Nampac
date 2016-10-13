#ifndef DEF_CHARACTER
#define DEF_CHARACTER

#include <SDL2/SDL.h>
#include <iostream>


using namespace std;

class Character{

	public:
		Character(char*,int,int,int,SDL_Renderer*);			
		int getSpeed();
		void changePosition(int,int);
		int getPosX();
		int getPosY();
		virtual SDL_Texture* getCharacterTexture();
		SDL_Rect* getTextureRect();
		int getDirection();
		void setDirection(int);
		virtual void destroySDLElements();




	protected:
		char* spriteLocation_;
		int speed_;
		SDL_Texture* characterTexture_;
		SDL_Surface* characterSurface_;
		SDL_Rect textureRect_;
		SDL_Renderer* renderer_;
		int direction_;


};


#endif