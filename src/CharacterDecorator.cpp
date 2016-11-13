#include <CharacterDecorator/CharacterDecorator.hpp>


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

vector<SDL_Texture*> CharacterDecorator::getCharacterTexture(){
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

void CharacterDecorator::changeStateHunter(){
	character_->changeStateHunter();
}


bool CharacterDecorator::canEatGhost(){
	return character_->canEatGhost();
}


void CharacterDecorator::setDeathPosition(){
	character_->setDeathPosition();
}

void CharacterDecorator::setMovementDeadState(){
	character_->setMovementDeadState();
}


void CharacterDecorator::setMovementChaseState(){
	character_->setMovementChaseState();
}

void CharacterDecorator::setMovementAmbushState(){
	character_->setMovementAmbushState();
}

void CharacterDecorator::setMovementUnpredictableState(){
	character_->setMovementUnpredictableState();
}

void CharacterDecorator::setMovementStupidState(){
	character_->setMovementStupidState();
}

void CharacterDecorator::backToClassicState(){
	character_->backToClassicState();
}

void CharacterDecorator::askChangeMovementChaseState(){
	character_->askChangeMovementChaseState();
}

void CharacterDecorator::askChangeMovementDeadState(){
	character_->askChangeMovementDeadState();
}

void CharacterDecorator::askChangeMovementAmbushState(){
	character_->askChangeMovementAmbushState();
}

void CharacterDecorator::askChangeMovementUnpredictableState(){
	character_->askChangeMovementUnpredictableState();
}

void CharacterDecorator::askChangeMovementStupidState(){
	character_->askChangeMovementStupidState();
}

