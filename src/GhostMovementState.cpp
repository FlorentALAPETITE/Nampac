#include <GhostMovementState.hpp>
#include <Ghost.hpp>
#include <GameEngine.hpp>

GhostMovementState::GhostMovementState(Ghost* g){
	ghost_ =g;
}


void GhostMovementState::moveCharacter(GameEngine* g,int speed){
	int newPosX, newPosY;

	switch (ghost_->getDirection()){

		case 0 : // right
			newPosX = ghost_->getPosX()+speed;
			newPosY = ghost_->getPosY();
			break; 

		case 1 :  // left
			newPosX = ghost_->getPosX()-speed;
			newPosY = ghost_->getPosY();
			break;

		case 2 :  //up
			newPosX = ghost_->getPosX();
			newPosY = ghost_->getPosY()-speed;
			break;

		case 3 : //down
			newPosX = ghost_->getPosX();
			newPosY = ghost_->getPosY()+speed;
			break;
	}

	if(newPosX>=680){
		ghost_->changePosition(0, newPosY);	
	}

	else if (newPosX<=0){
		ghost_->changePosition(680, newPosY);
	}

	else {
		if( !g->checkColision(newPosX,newPosY))
			ghost_->changePosition(newPosX, newPosY);	
	}		
		
}