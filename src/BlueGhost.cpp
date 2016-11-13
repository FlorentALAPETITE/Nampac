#include <Character/BlueGhost.hpp>
#include <iostream>


BlueGhost::BlueGhost(int posX, int posY, SDL_Renderer* renderer):Ghost((char*)"sprites/Ghosts/blueGhost.bmp",posX,posY,renderer,11*25,13*25){	
}

BlueGhost::BlueGhost(const BlueGhost &bg):Ghost(bg){
	currentMovementState_ = movementUnpredictableState_;
	currentMovementState_->setLifeTime(-1);
}

void BlueGhost::backToClassicState(){
	if(currentMovementState_!=movementUnpredictableState_){
		currentMovementState_=movementUnpredictableState_;
	}
}



shared_ptr<BlueGhost> BlueGhost::clone(int c, int l){
	shared_ptr<BlueGhost> bonus = make_shared<BlueGhost>(*this);
	bonus->changePosition(c,l);
	return bonus;
}