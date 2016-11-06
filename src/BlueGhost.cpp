#include <BlueGhost.hpp>
#include <iostream>


BlueGhost::BlueGhost(int posX, int posY, SDL_Renderer* renderer):Ghost((char*)"sprites/blueGhost.bmp",posX,posY,renderer,11*25,13*25){	
	currentMovementState_ = movementUnpredictableState_;
	currentMovementState_->setLifeTime(-1);
}

void BlueGhost::backToClassicState(){
	if(currentMovementState_!=movementUnpredictableState_){
		currentMovementState_=movementUnpredictableState_;
	}
}