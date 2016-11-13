#include <Character/RedGhost.hpp>
#include <iostream>


RedGhost::RedGhost(int posX, int posY, SDL_Renderer* renderer):Ghost((char*)"sprites/Ghosts/redGhost.bmp",posX,posY,renderer,16*25,15*25){	
}

RedGhost::RedGhost(const RedGhost &rg):Ghost(rg){
	currentMovementState_ = movementChaseState_;
	currentMovementState_->setLifeTime(-1);
}

void RedGhost::backToClassicState(){
	if(currentMovementState_!=movementChaseState_){
		currentMovementState_=movementChaseState_;
	}
}



shared_ptr<RedGhost> RedGhost::clone(int c, int l){
	shared_ptr<RedGhost> bonus = make_shared<RedGhost>(*this);
	bonus->changePosition(c,l);
	return bonus;
}