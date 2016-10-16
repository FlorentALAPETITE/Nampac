#include <GhostMovementUnpredictable.hpp>
#include <Ghost.hpp>
#include <stdlib.h>    
#include <time.h>   


void GhostMovementUnpredictable::calculateDirection(){
	ghost_->setDirection(rand() % 4);

}


GhostMovementUnpredictable::GhostMovementUnpredictable(Ghost *g):GhostMovementState(g){}