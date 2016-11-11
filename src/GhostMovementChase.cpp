#include <GhostMovementState/GhostMovementChase.hpp>
#include <stdlib.h>  
#include <Character/Ghost.hpp>

GhostMovementChase::GhostMovementChase(Ghost* g):GhostMovementState(g){}

void GhostMovementChase::calculateDirection(){
	if(nextDirectionCalc_==30){
		ghost_->setDirection(rand() % 4);
		nextDirectionCalc_=0;
	}
	else
		++nextDirectionCalc_;

}


