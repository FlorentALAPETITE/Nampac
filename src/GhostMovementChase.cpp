#include <GhostMovementChase.hpp>
#include <GhostMovementState.hpp>
#include <Ghost.hpp>
#include <stdlib.h>    
#include <time.h>   


void GhostMovementChase::calculateDirection(){
	srand (time(NULL));

	ghost_->setDirection(rand() % 4);

}


GhostMovementChase::GhostMovementChase(Ghost *g):GhostMovementState(g){}