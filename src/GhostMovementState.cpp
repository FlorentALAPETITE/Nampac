#include <GhostMovementState/GhostMovementState.hpp>
#include <Character/Ghost.hpp>
#include <GameEngine.hpp>

GhostMovementState::GhostMovementState(Ghost* g):ghost_(g),nextDirectionCalc_(0),stateLifeTime_(150){
}


void GhostMovementState::moveCharacter(GameEngine* g,int speed){
	
	int modifiedSpeed = speed;
	bool modified=false;
	while(modified==false && modifiedSpeed!=0){

			int newPosX, newPosY;		
			switch (ghost_->getDirection()){

				case 0 : // right
					newPosX = ghost_->getPosX()+modifiedSpeed;
					newPosY = ghost_->getPosY();
					break; 

				case 1 :  // left
					newPosX = ghost_->getPosX()-modifiedSpeed;
					newPosY = ghost_->getPosY();
					break;

				case 2 :  //up
					newPosX = ghost_->getPosX();
					newPosY = ghost_->getPosY()-modifiedSpeed;
					break;

				case 3 : //down
					newPosX = ghost_->getPosX();
					newPosY = ghost_->getPosY()+modifiedSpeed;
					break;
			}

			if(newPosX>=671){
				ghost_->changePosition(0, newPosY);	
				modified=true;
			}

			else if (newPosX<0){
				ghost_->changePosition(672, newPosY);
				modified=true;
			}

			else if(newPosY>=748){
				ghost_->changePosition(newPosX, 0);
				modified=true;
			}

			else if(newPosY<=0){
				ghost_->changePosition(newPosX, 749);
				modified=true;
			}


			else{ 
				if( !g->checkColision(newPosX,newPosY)){
					ghost_->changePosition(newPosX, newPosY);
					modified=true;
				}
			}		
			--modifiedSpeed;
		}

	--stateLifeTime_;

	if(stateLifeTime_==0){
		stateLifeTime_=150;
		backToClassicState();		
	}
}


void GhostMovementState::setMovementDeadState(){
	ghost_->setMovementDeadState();
}
		
void GhostMovementState::setMovementAmbushState(){
	ghost_->setMovementAmbushState();
}
	
void GhostMovementState::setMovementStupidState(){
	ghost_->setMovementStupidState();
}

void GhostMovementState::setMovementUnpredictableState(){
	ghost_->setMovementUnpredictableState();
}

void GhostMovementState::setMovementChaseState(){
	ghost_->setMovementChaseState();
}

void GhostMovementState::backToClassicState(){
	ghost_->backToClassicState();
}

void GhostMovementState::setLifeTime(int lifeTime){
	stateLifeTime_=lifeTime;
}