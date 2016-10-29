#include <GhostMovementStupid.hpp>
#include <stdlib.h>  
#include <Ghost.hpp>

void GhostMovementStupid::calculateDirection(){
	ghost_->setDirection(rand() % 4);

}


GhostMovementStupid::GhostMovementStupid(Ghost *g):GhostMovementState(g){}