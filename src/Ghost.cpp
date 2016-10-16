#include <Ghost.hpp>
#include <iostream>


Ghost::Ghost(char* sp,int posX, int posY, SDL_Renderer* renderer):Character(sp,5,posX,posY,renderer){
	movementChaseState_ = shared_ptr<GhostMovementChase>(new GhostMovementChase(this));
	movementAmbushState_ = shared_ptr<GhostMovementAmbush>(new GhostMovementAmbush(this));
	movementStupidState_ = shared_ptr<GhostMovementStupid>(new GhostMovementStupid(this));
	movementUnpredictableState_ = shared_ptr<GhostMovementUnpredictable>(new GhostMovementUnpredictable(this));
}


void Ghost::calculateNextDirection(){
	currentMovementState_->calculateDirection();
}