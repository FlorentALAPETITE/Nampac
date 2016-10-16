#include <GhostMovementChase.hpp>
#include <Ghost.hpp>
#include <stdlib.h>    



void GhostMovementChase::calculateDirection(){
	ghost_->setDirection(rand() % 4);

}


GhostMovementChase::GhostMovementChase(Ghost *g):GhostMovementState(g){}