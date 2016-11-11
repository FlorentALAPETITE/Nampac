#include <GhostMovementState/GhostMovementDead.hpp>
#include <Character/Ghost.hpp>
#include <stdlib.h>     


void GhostMovementDead::calculateDirection(){}


GhostMovementDead::GhostMovementDead(Ghost* g):GhostMovementState(g){}

void GhostMovementDead::moveCharacter(GameEngine*, int speed){
	--stateLifeTime_;

	if(stateLifeTime_==0){
		stateLifeTime_=150;
		ghost_->changePosition(14*25,11*25);
		backToClassicState();		
	}
}


void GhostMovementDead::setMovementDeadState(){}
		
void GhostMovementDead::setMovementAmbushState(){}
	
void GhostMovementDead::setMovementStupidState(){}

void GhostMovementDead::setMovementUnpredictableState(){}

void GhostMovementDead::setMovementChaseState(){}
