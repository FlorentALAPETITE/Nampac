#include <PinkGhost.hpp>
#include <iostream>


PinkGhost::PinkGhost(int posX, int posY, SDL_Renderer* renderer):Ghost((char*)"sprites/pinkGhost.bmp",posX,posY,renderer,16*25,13*25){	
	currentMovementState_ = movementAmbushState_;
	currentMovementState_->setLifeTime(-1);
}

void PinkGhost::backToClassicState(){
	if(currentMovementState_!=movementAmbushState_){
		currentMovementState_=movementAmbushState_;
	}
}