#include <Character.hpp>
#include <iostream>
#include <GameEngine.hpp>

using namespace std;


Character::Character(char* sl, int s, int posX, int posY,SDL_Renderer* renderer):speed_(s),renderer_(renderer),direction_(0){	
	characterSurface_ = SDL_LoadBMP(sl);
	characterTexture_ = SDL_CreateTextureFromSurface(renderer_,characterSurface_);

	textureRect_ = { posX,posY, 25, 25};


	if(!characterSurface_ or !characterTexture_)
		throw string("Impossible de charger le personnage");

}

Character::Character(){}


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


vector<SDL_Texture*> Character::getCharacterTexture(){
	vector<SDL_Texture*> res = vector<SDL_Texture*>();
	res.push_back(characterTexture_);
	return res;
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

Character::~Character(){
	if(characterTexture_!=nullptr)
		SDL_DestroyTexture(characterTexture_);
	if(characterSurface_!=nullptr)
		SDL_FreeSurface(characterSurface_);
}


void Character::changeStateHunter(){}


bool Character::canEatGhost(){
	return false;
}

void Character::setDeathPosition(){}


void Character::setMovementDeadState(){}
		
void Character::setMovementAmbushState(){}
	
void Character::setMovementStupidState(){}

void Character::setMovementUnpredictableState(){}

void Character::setMovementChaseState(){}

void Character::backToClassicState(){}


void Character::askChangeMovementDeadState(){}
		
void Character::askChangeMovementAmbushState(){}
	
void Character::askChangeMovementStupidState(){}

void Character::askChangeMovementUnpredictableState(){}

void Character::askChangeMovementChaseState(){}

