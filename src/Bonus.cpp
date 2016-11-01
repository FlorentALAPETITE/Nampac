#include <Bonus.hpp>
#include <iostream>

using namespace std;

Bonus::Bonus(SDL_Renderer* renderer, int posX, int posY, int size,const char* sprite ):renderer_(renderer){
	bonusTextureRect_ = { posX,posY,size,size};
	bonusSurface_ = SDL_LoadBMP(sprite);
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

