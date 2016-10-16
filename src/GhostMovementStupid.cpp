#include <GhostMovementStupid.hpp>
#include <Ghost.hpp>
#include <stdlib.h>    



void GhostMovementStupid::calculateDirection(){
	ghost_->setDirection(rand() % 4);

}


GhostMovementStupid::GhostMovementStupid(Ghost *g):GhostMovementState(g){}