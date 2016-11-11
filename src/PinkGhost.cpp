#include <Character/PinkGhost.hpp>
#include <iostream>


PinkGhost::PinkGhost(int posX, int posY, SDL_Renderer* renderer):Ghost((char*)"sprites/Ghosts/pinkGhost.bmp",posX,posY,renderer,16*25,13*25){	
}

PinkGhost::PinkGhost(const PinkGhost &pg):Ghost(pg){
	currentMovementState_ = movementAmbushState_;
	currentMovementState_->setLifeTime(-1);
}

void PinkGhost::backToClassicState(){
	if(currentMovementState_!=movementAmbushState_){
		currentMovementState_=movementAmbushState_;
	}
}


shared_ptr<PinkGhost> PinkGhost::clone(){
	return make_shared<PinkGhost>(*this);
}