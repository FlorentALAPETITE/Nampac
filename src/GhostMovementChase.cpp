#include <GhostMovementChase.hpp>
#include <stdlib.h>  
#include <Ghost.hpp>

void GhostMovementChase::calculateDirection(){
	ghost_->setDirection(rand() % 4);

}


GhostMovementChase::GhostMovementChase(Ghost *g):GhostMovementState(g){}