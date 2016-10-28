#include <Gomme.hpp>
#include <iostream>

using namespace std;

Gomme::Gomme(SDL_Renderer* renderer):renderer_(renderer){
	GommeTextureRect_ = { 10,10,20,20};
	GommeSurface_ = SDL_LoadBMP("sprites/gomme.bmp");
	GommeTexture_ = SDL_CreateTextureFromSurface(renderer_,GommeSurface_);
	if(!GommeSurface_ or !GommeTexture_){
		throw string("Impossible de charger le bonus gomme");
	}
}

void Gomme::setBonusTextureRect(int x, int y){
	GommeTextureRect_ = { x,y, 10, 10};
}

SDL_Rect* Gomme::getTextureRect(){ return &GommeTextureRect_; }	
SDL_Texture* Gomme::getTexture(){ 
	return GommeTexture_; 
}