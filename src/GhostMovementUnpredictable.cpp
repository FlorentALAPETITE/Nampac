#include <GhostMovementState/GhostMovementUnpredictable.hpp>
#include <stdlib.h>    
#include <time.h>  
#include <Character/Ghost.hpp>


void GhostMovementUnpredictable::calculateDirection(){
	if(nextDirectionCalc_==8){
		ghost_->setDirection(rand() % 4);
		nextDirectionCalc_=0;
	}
	else
		++nextDirectionCalc_;

}


GhostMovementUnpredictable::GhostMovementUnpredictable(Ghost *g):GhostMovementState(g){}