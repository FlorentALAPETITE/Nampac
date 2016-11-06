#include <RedGhost.hpp>
#include <iostream>


RedGhost::RedGhost(int posX, int posY, SDL_Renderer* renderer):Ghost((char*)"sprites/redGhost.bmp",posX,posY,renderer,16*25,18*25){	
	currentMovementState_ = movementChaseState_;
	currentMovementState_->setLifeTime(-1);
}

void RedGhost::backToClassicState(){
	if(currentMovementState_!=movementChaseState_){
		currentMovementState_=movementChaseState_;
	}
}