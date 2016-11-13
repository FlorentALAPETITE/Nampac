#include <GhostMovementState/GhostMovementStupid.hpp>
#include <stdlib.h>  
#include <Character/Ghost.hpp>

GhostMovementStupid::GhostMovementStupid(Ghost* g):GhostMovementState(g){}

void GhostMovementStupid::calculateDirection(){
	ghost_->setDirection(rand() % 4);

}


