#include <GhostMovementState/GhostMovementAmbush.hpp>
#include <stdlib.h>     
#include <Character/Ghost.hpp>


GhostMovementAmbush::GhostMovementAmbush(Ghost* g):GhostMovementState(g){}


void GhostMovementAmbush::calculateDirection(){
	if(nextDirectionCalc_==15){
		ghost_->setDirection(rand() % 4);
		nextDirectionCalc_=0;
	}
	else
		++nextDirectionCalc_;

}

