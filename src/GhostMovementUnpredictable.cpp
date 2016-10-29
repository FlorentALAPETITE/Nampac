#include <GhostMovementUnpredictable.hpp>
#include <stdlib.h>    
#include <time.h>  
#include <Ghost.hpp>


void GhostMovementUnpredictable::calculateDirection(){
	ghost_->setDirection(rand() % 4);

}


GhostMovementUnpredictable::GhostMovementUnpredictable(Ghost *g):GhostMovementState(g){}