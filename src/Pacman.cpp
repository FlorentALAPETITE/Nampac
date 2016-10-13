#include <Pacman.hpp>
#include <iostream>

using namespace std;


Pacman::Pacman(char* sp,int s, int posX, int posY, SDL_Renderer* renderer):Character(sp,s,posX,posY,renderer), open_(0){

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

	if(open_<=3){
		open_+=1;
		return characterTexture_;
	}

	else{
		if (open_=6)
			open_=0;
		else
			open_+=1;
	
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


void Pacman::destroySDLElements(){
	SDL_DestroyTexture(characterTexture_);
	SDL_FreeSurface(characterSurface_);

	SDL_DestroyTexture(characterTextureOpenBot_);
	SDL_FreeSurface(characterSurfaceOpenBot_);

	SDL_DestroyTexture(characterTextureOpenLeft_);
	SDL_FreeSurface(characterSurfaceOpenLeft_);

	SDL_DestroyTexture(characterTextureOpenRight_);
	SDL_FreeSurface(characterSurfaceOpenRight_);

	SDL_DestroyTexture(characterTextureOpenTop_);
	SDL_FreeSurface(characterSurfaceOpenTop_);
}

