#include <Character/OrangeGhost.hpp>
#include <iostream>


OrangeGhost::OrangeGhost(int posX, int posY, SDL_Renderer* renderer):Ghost((char*)"sprites/Ghosts/orangeGhost.bmp",posX,posY,renderer,11*25,15*25){	
}

OrangeGhost::OrangeGhost(const OrangeGhost &og):Ghost(og){	
	currentMovementState_ = movementStupidState_;
	currentMovementState_->setLifeTime(-1);
}	

void OrangeGhost::backToClassicState(){
	if(currentMovementState_!=movementStupidState_){
		currentMovementState_=movementStupidState_;
	}
}


shared_ptr<OrangeGhost> OrangeGhost::clone(){
	return make_shared<OrangeGhost>(*this);
}