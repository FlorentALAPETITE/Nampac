#include <Bonus.hpp>
#include <iostream>

using namespace std;

Bonus::Bonus(SDL_Renderer* renderer, int posX, int posY, int size,const char* spriteLocation ):renderer_(renderer){
	bonusTextureRect_ = { posX,posY,size,size};
	bonusSurface_ = SDL_LoadBMP(spriteLocation);
	bonusTexture_ = SDL_CreateTextureFromSurface(renderer_,bonusSurface_);
	if(!bonusSurface_ || !bonusTexture_){
		throw string("Impossible de charger le bonus");
	}
}


SDL_Rect* Bonus::getTextureRect(){ 
	return &bonusTextureRect_; 
}	


SDL_Texture* Bonus::getTexture(){ 
	return bonusTexture_; 
}


Bonus::~Bonus(){	
	if(bonusTexture_!=nullptr)
		SDL_DestroyTexture(bonusTexture_);

	if(bonusSurface_!=nullptr)
		SDL_FreeSurface(bonusSurface_);
}