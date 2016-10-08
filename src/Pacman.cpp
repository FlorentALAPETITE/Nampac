#include <Pacman.hpp>
#include <iostream>

using namespace std;


Pacman::Pacman(char* sp,int s, int posX, int posY, SDL_Renderer* renderer):Character(sp,s,posX,posY,renderer), open_(true){

	characterSurfaceOpenTop_ = SDL_LoadBMP("sprites/pacmanOpenTop.bmp");
	characterTextureOpenTop_ = SDL_CreateTextureFromSurface(renderer_,characterSurfaceOpenTop_);

	characterSurfaceOpenBot_ = SDL_LoadBMP("sprites/pacmanOpenBot.bmp");
	characterTextureOpenBot_ = SDL_CreateTextureFromSurface(renderer_,characterSurfaceOpenBot_);

	characterSurfaceOpenLeft_ = SDL_LoadBMP("sprites/pacmanOpenLeft.bmp");
	characterTextureOpenLeft_ = SDL_CreateTextureFromSurface(renderer_,characterSurfaceOpenLeft_);

	characterSurfaceOpenRight_ = SDL_LoadBMP("sprites/pacmanOpenRight.bmp");
	characterTextureOpenRight_ = SDL_CreateTextureFromSurface(renderer_,characterSurfaceOpenRight_);

	
}



SDL_Texture* Pacman::getCharacterTexture(){

	if(!open_){
		open_=true;
		return characterTexture_;
	}

	else{
		open_=false;
	
		switch (direction_){
			case 0 : // right
				return characterTextureOpenRight_;
				break; 
			case 1 :  // left
				return characterTextureOpenLeft_;
				break;
			case 2 :  //up
				return characterTextureOpenTop_;
				break;
			case 3 : //down
				return characterTextureOpenBot_;
				break;
		}
	}
}

