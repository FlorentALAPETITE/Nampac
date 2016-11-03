#include <GhostMovementState.hpp>
#include <Ghost.hpp>
#include <GameEngine.hpp>

GhostMovementState::GhostMovementState(Ghost* g){
	ghost_ =g;
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

	

		
}