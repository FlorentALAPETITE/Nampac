#include <Ghost.hpp>
#include <iostream>


Ghost::Ghost(char* sp,int posX, int posY, SDL_Renderer* renderer):Character(sp,5,posX,posY,renderer){}


void Ghost::calculateNextDirection(){
	currentMovementState_->calculateDirection();
}