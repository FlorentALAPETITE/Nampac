#include <GhostMovementAmbush.hpp>
#include <Ghost.hpp>
#include <stdlib.h>     


void GhostMovementAmbush::calculateDirection(){
	ghost_->setDirection(rand() % 4);

}


GhostMovementAmbush::GhostMovementAmbush(Ghost *g):GhostMovementState(g){}