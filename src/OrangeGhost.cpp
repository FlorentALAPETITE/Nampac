#include <OrangeGhost.hpp>
#include <iostream>


OrangeGhost::OrangeGhost(int posX, int posY, SDL_Renderer* renderer):Ghost((char*)"sprites/orangeGhost.bmp",posX,posY,renderer,11*25,18*25){	
	currentMovementState_ = movementStupidState_;
	currentMovementState_->setLifeTime(-1);
}

void OrangeGhost::backToClassicState(){
	if(currentMovementState_!=movementStupidState_){
		currentMovementState_=movementStupidState_;
	}
}