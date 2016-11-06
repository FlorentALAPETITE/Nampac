#include <CharacterDecorator.hpp>


CharacterDecorator::CharacterDecorator(shared_ptr<Character> c):character_(c){
	characterTexture_=nullptr;
	characterSurface_=nullptr;
}


void CharacterDecorator::changePosition(int x,int y){
	character_->changePosition(x,y);
}

int CharacterDecorator::getPosX(){
	return character_->getPosX();
}

int CharacterDecorator::getPosY(){
	return character_->getPosY();
}

SDL_Texture* CharacterDecorator::getCharacterTexture(){
	return character_->getCharacterTexture();
}

SDL_Rect* CharacterDecorator::getTextureRect() {
	return character_->getTextureRect();
}

int CharacterDecorator::getDirection(){
	return character_->getDirection();
}

void CharacterDecorator::setDirection(int d){
	character_->setDirection(d);
}


void CharacterDecorator::moveCharacter(GameEngine* g,int speed){
	character_->moveCharacter(g, speed);
}

void CharacterDecorator::calculateNextDirection(){
	character_->calculateNextDirection();
}

