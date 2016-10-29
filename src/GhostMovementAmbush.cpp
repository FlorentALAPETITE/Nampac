#include <GhostMovementAmbush.hpp>
#include <stdlib.h>     
#include <Ghost.hpp>


void GhostMovementAmbush::calculateDirection(){
	ghost_->setDirection(rand() % 4);

}


GhostMovementAmbush::GhostMovementAmbush(Ghost *g):GhostMovementState(g){}