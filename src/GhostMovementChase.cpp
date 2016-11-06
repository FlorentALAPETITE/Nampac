#include <GhostMovementChase.hpp>
#include <stdlib.h>  
#include <Ghost.hpp>

void GhostMovementChase::calculateDirection(){
	if(nextDirectionCalc_==30){
		ghost_->setDirection(rand() % 4);
		nextDirectionCalc_=0;
	}
	else
		++nextDirectionCalc_;

}


GhostMovementChase::GhostMovementChase(Ghost *g):GhostMovementState(g){}