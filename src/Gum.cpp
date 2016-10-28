#include <Gum.hpp>
#include <iostream>

using namespace std;

Gum::Gum(SDL_Renderer* renderer, int posX, int posY):renderer_(renderer){
	gumTextureRect_ = { posX,posY,10,10};
	gumSurface_ = SDL_LoadBMP("sprites/gum.bmp");
	gumTexture_ = SDL_CreateTextureFromSurface(renderer_,gumSurface_);
	if(!gumSurface_ || !gumTexture_){
		throw string("Impossible de charger le bonus gum");
	}
}


SDL_Rect* Gum::getTextureRect(){ 
	return &gumTextureRect_; 
}	


SDL_Texture* Gum::getTexture(){ 
	return gumTexture_; 
}