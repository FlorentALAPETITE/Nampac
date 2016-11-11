#include <Character/Ghost.hpp>
#include <GhostMovementState/GhostMovementChase.hpp>
#include <GhostMovementState/GhostMovementAmbush.hpp>
#include <GhostMovementState/GhostMovementStupid.hpp>
#include <GhostMovementState/GhostMovementUnpredictable.hpp>
#include <GhostMovementState/GhostMovementDead.hpp>
#include <iostream>


Ghost::Ghost(char* sp,int posX, int posY, SDL_Renderer* renderer,int deathPosX, int deathPosY):Character(sp,5,posX,posY,renderer),deathPosX_(deathPosX),deathPosY_(deathPosY){
}


Ghost::Ghost(const Ghost &ghost): Character(ghost),deathPosX_(ghost.deathPosX_),deathPosY_(ghost.deathPosY_){//,currentMovementState_(ghost.currentMovementState_),movementChaseState_(ghost.movementChaseState_),movementAmbushState_(ghost.movementAmbushState_),movementStupidState_(ghost.movementStupidState_),movementUnpredictableState_(ghost.movementUnpredictableState_),movementDeadState_(ghost.movementDeadState_),  deathPosX_(ghost.deathPosX_),deathPosY_(ghost.deathPosY_){
	movementChaseState_ = shared_ptr<GhostMovementChase>(new GhostMovementChase(this));
	movementAmbushState_ = shared_ptr<GhostMovementAmbush>(new GhostMovementAmbush(this));
	movementStupidState_ = shared_ptr<GhostMovementStupid>(new GhostMovementStupid(this));
	movementUnpredictableState_ = shared_ptr<GhostMovementUnpredictable>(new GhostMovementUnpredictable(this));
	movementDeadState_ = shared_ptr<GhostMovementDead>(new GhostMovementDead(this));
}



void Ghost::calculateNextDirection(){
	currentMovementState_->calculateDirection();
}




void Ghost::moveCharacter(GameEngine* g,int speed){
	currentMovementState_->moveCharacter(g, speed);		
}

void Ghost::setDeathPosition(){
	changePosition(deathPosX_,deathPosY_);
}


void Ghost::askChangeMovementDeadState(){
	currentMovementState_->setMovementDeadState();
}
		
void Ghost::askChangeMovementAmbushState(){
	currentMovementState_->setMovementAmbushState();
}
	
void Ghost::askChangeMovementStupidState(){
	currentMovementState_->setMovementStupidState();
}

void Ghost::askChangeMovementUnpredictableState(){
	currentMovementState_->setMovementUnpredictableState();
}

void Ghost::askChangeMovementChaseState(){
	currentMovementState_->setMovementChaseState();
}


void Ghost::setMovementDeadState(){
	currentMovementState_=movementDeadState_;
}
		
void Ghost::setMovementAmbushState(){
	currentMovementState_=movementAmbushState_;
}
	
void Ghost::setMovementStupidState(){
	currentMovementState_=movementStupidState_;
}

void Ghost::setMovementUnpredictableState(){
	currentMovementState_=movementUnpredictableState_;
}

void Ghost::setMovementChaseState(){
	currentMovementState_=movementChaseState_;
}
