
#include <MapElement.hpp>
#include <iostream>



MapElement::MapElement(char* sl, int posX, int posY,SDL_Renderer* renderer, shared_ptr<Bonus> b):renderer_(renderer), bonus_(b){	
	mapElementSurface_ = SDL_LoadBMP(sl);
	mapElementTexture_ = SDL_CreateTextureFromSurface(renderer_,mapElementSurface_);

	textureRect_ = { posX,posY, 25, 25};


	if(!mapElementSurface_ or !mapElementTexture_)
		throw string("Impossible de charger la map");

}



SDL_Texture* MapElement::getMapElementTexture(){
	return mapElementTexture_;
}

SDL_Rect* MapElement::getTextureRect(){
	return &textureRect_;
}

void MapElement::destroySDLElements(){
	SDL_DestroyTexture(mapElementTexture_);
	SDL_FreeSurface(mapElementSurface_);
}


shared_ptr<Bonus> MapElement::getBonus(){
	return bonus_;
}

void MapElement::eatBonus(){
	bonus_=nullptr;
}
