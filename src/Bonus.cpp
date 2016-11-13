#include <Bonus/Bonus.hpp>
#include <iostream>

using namespace std;

Bonus::Bonus(SDL_Renderer* renderer, int posX, int posY, int size, char* spriteLocation ):renderer_(renderer), spriteLocation_(spriteLocation){
	bonusTextureRect_ = { posX,posY,size,size};
	bonusSurface_ = SDL_LoadBMP(spriteLocation_);
	bonusTexture_ = SDL_CreateTextureFromSurface(renderer_,bonusSurface_);
	if(!bonusSurface_ || !bonusTexture_){
		throw string("Impossible de charger le bonus");
	}
}

Bonus::Bonus(const Bonus &bonus): bonusTextureRect_(bonus.bonusTextureRect_),renderer_(bonus.renderer_),spriteLocation_(bonus.spriteLocation_){

	// Can't be pointed from another object, has to be reallocated (SDL particularity)
	bonusSurface_ = SDL_LoadBMP(spriteLocation_);
	bonusTexture_ = SDL_CreateTextureFromSurface(renderer_,bonusSurface_);
}


void Bonus::setPosition(int newPosX, int newPosY){
	bonusTextureRect_.x=newPosX;
	bonusTextureRect_.y=newPosY;
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