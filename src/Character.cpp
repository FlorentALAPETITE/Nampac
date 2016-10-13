#include <Character.hpp>
#include <iostream>

using namespace std;


Character::Character(char* sl, int s, int posX, int posY,SDL_Renderer* renderer):spriteLocation_(sl),speed_(s),renderer_(renderer),direction_(0){	
	characterSurface_ = SDL_LoadBMP(spriteLocation_);
	characterTexture_ = SDL_CreateTextureFromSurface(renderer_,characterSurface_);

	textureRect_ = { posX,posY, 25, 25};


	if(!characterSurface_ or !characterTexture_)
		throw string("Impossible de charger le personnage");

}


int Character::getSpeed(){
	return speed_;
}

void Character::changePosition(int newPosX, int newPosY){
	textureRect_.x=newPosX;
	textureRect_.y=newPosY;
}


int Character::getPosX(){
	return textureRect_.x;
}

int Character::getPosY(){
	return textureRect_.y;
}


SDL_Texture* Character::getCharacterTexture(){
	return characterTexture_;
}

SDL_Rect* Character::getTextureRect(){
	return &textureRect_;
}

int Character::getDirection(){
	return direction_;
}
		
void Character::setDirection(int d){
	direction_=d;
}

void Character::destroySDLElements(){
	SDL_DestroyTexture(characterTexture_);
	SDL_FreeSurface(characterSurface_);
}