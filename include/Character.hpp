#ifndef DEF_CHARACTER
#define DEF_CHARACTER

#include <SDL2/SDL.h>
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class GameEngine;

class Character{

	public:
		Character(char*,int,int,int,SDL_Renderer*);	
		Character();	
		~Character();	
		virtual int getSpeed();
		virtual void changePosition(int,int);
		virtual int getPosX();
		virtual int getPosY();
		virtual vector<SDL_Texture*> getCharacterTexture();
		virtual SDL_Rect* getTextureRect();
		virtual int getDirection();
		virtual void setDirection(int);
		virtual void moveCharacter(GameEngine*,int)=0;
		virtual void calculateNextDirection()=0;
		virtual void changeStateHunter();


	protected:
		
		int speed_;
		SDL_Texture* characterTexture_;
		SDL_Surface* characterSurface_;
		SDL_Rect textureRect_;
		SDL_Renderer* renderer_;
		int direction_;


};


#endif