#include <MapElement/MapElement.hpp>
#include <iostream>



MapElement::MapElement(char* sl, int posX, int posY,SDL_Renderer* renderer):renderer_(renderer),spriteLocation_(sl){	
	mapElementSurface_ = SDL_LoadBMP(spriteLocation_);
	mapElementTexture_ = SDL_CreateTextureFromSurface(renderer_,mapElementSurface_);

	textureRect_ = { posX,posY, 25, 25};


	if(!mapElementSurface_ or !mapElementTexture_)
		throw string("Impossible de charger la map");

}

MapElement::MapElement(const MapElement &mapElement):textureRect_(mapElement.textureRect_),renderer_(mapElement.renderer_),spriteLocation_(mapElement.spriteLocation_){
	// Can't be pointed from another object, has to be reallocated (SDL particularity)
	mapElementSurface_ = SDL_LoadBMP(spriteLocation_);
	mapElementTexture_ = SDL_CreateTextureFromSurface(renderer_,mapElementSurface_);
}



SDL_Texture* MapElement::getMapElementTexture(){
	return mapElementTexture_;
}

SDL_Rect* MapElement::getTextureRect(){
	return &textureRect_;
}

 MapElement::~MapElement(){
	SDL_DestroyTexture(mapElementTexture_);
	SDL_FreeSurface(mapElementSurface_);
}


shared_ptr<Bonus> MapElement::getBonus(){
	return bonus_;
}

void MapElement::eatBonus(){
	bonus_=nullptr;
}

void MapElement::setBonus(shared_ptr<Bonus> b){
	bonus_ = b;
}

void MapElement::setPosition(int newPosX, int newPosY){
	textureRect_.x=newPosX;
	textureRect_.y=newPosY;
}
