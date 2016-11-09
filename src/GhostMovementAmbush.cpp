#include <GhostMovementState/GhostMovementAmbush.hpp>
#include <stdlib.h>     
#include <Character/Ghost.hpp>


void GhostMovementAmbush::calculateDirection(){
	if(nextDirectionCalc_==15){
		ghost_->setDirection(rand() % 4);
		nextDirectionCalc_=0;
	}
	else
		++nextDirectionCalc_;

}


GhostMovementAmbush::GhostMovementAmbush(Ghost *g):GhostMovementState(g){}