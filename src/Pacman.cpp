#include <Pacman.hpp>
#include <GameEngine.hpp>
#include <iostream>
#include <PreyState.hpp>
#include <HunterState.hpp>

using namespace std;


Pacman::Pacman(char* sp,int s, int posX, int posY, SDL_Renderer* renderer):Character(sp,s,posX,posY,renderer), open_(0){

	characterSurfaceOpenTop_ = SDL_LoadBMP("sprites/pacmanOpenTop.bmp");
	characterTextureOpenTop_ = SDL_CreateTextureFromSurface(renderer_,characterSurfaceOpenTop_);

	characterSurfaceOpenBot_ = SDL_LoadBMP("sprites/pacmanOpenBot.bmp");
	characterTextureOpenBot_ = SDL_CreateTextureFromSurface(renderer_,characterSurfaceOpenBot_);

	characterSurfaceOpenLeft_ = SDL_LoadBMP("sprites/pacmanOpenLeft.bmp");
	characterTextureOpenLeft_ = SDL_CreateTextureFromSurface(renderer_,characterSurfaceOpenLeft_);

	characterSurfaceOpenRight_ = SDL_LoadBMP("sprites/pacmanOpenRight.bmp");
	characterTextureOpenRight_ = SDL_CreateTextureFromSurface(renderer_,characterSurfaceOpenRight_);

	hunterParticleSurface_ = SDL_LoadBMP("sprites/hunterParticle.bmp");
	hunterParticleTexture_ = SDL_CreateTextureFromSurface(renderer_,hunterParticleSurface_);

	requestedDirection_=9;

	hunterState_ = shared_ptr<HunterState>(new HunterState(this));
	preyState_ = shared_ptr<PreyState>(new PreyState(this));

	currentState_ = preyState_;
	
}

vector<SDL_Texture*> Pacman::getCharacterTexture(){
	
	vector<SDL_Texture*> res = vector<SDL_Texture*>();

	if(open_<=4){
		open_+=1;
		res.push_back(characterTexture_);
	}

	else{
		if (open_ == 8)
			open_=0;
		else
			open_+=1;
	
		switch (direction_){
			case 0 : // right
				res.push_back(characterTextureOpenRight_);
				break; 
			case 1 :  // left
				res.push_back(characterTextureOpenLeft_);
				break;
			case 2 :  //up
				res.push_back(characterTextureOpenTop_);
				break;
			case 3 : //down
				res.push_back(characterTextureOpenBot_);
				break;
		}		
	}

	if(canEatGhost())
		res.push_back(hunterParticleTexture_);
	
	return res;
}


Pacman::~Pacman(){	

	if(characterTextureOpenBot_!=nullptr)
		SDL_DestroyTexture(characterTextureOpenBot_);

	if(characterSurfaceOpenBot_!=nullptr)
		SDL_FreeSurface(characterSurfaceOpenBot_);

	if(characterTextureOpenLeft_!=nullptr)
		SDL_DestroyTexture(characterTextureOpenLeft_);

	if(characterSurfaceOpenLeft_!=nullptr)		
		SDL_FreeSurface(characterSurfaceOpenLeft_);

	if(characterTextureOpenRight_!=nullptr)
		SDL_DestroyTexture(characterTextureOpenRight_);

	if(characterSurfaceOpenRight_)
		SDL_FreeSurface(characterSurfaceOpenRight_);

	if(characterTextureOpenTop_!=nullptr)
		SDL_DestroyTexture(characterTextureOpenTop_);

	if(characterSurfaceOpenTop_!=nullptr)
		SDL_FreeSurface(characterSurfaceOpenTop_);

	if(hunterParticleTexture_!=nullptr)
		SDL_DestroyTexture(hunterParticleTexture_);

	if(hunterParticleSurface_!=nullptr)
		SDL_FreeSurface(hunterParticleSurface_);
}



void Pacman::moveCharacter(GameEngine* g, int speed){

	
	bool modified=false;
	int move = 0;	
	int newPosX, newPosY;
	int modifiedSpeed;

	if(requestedDirection_!=direction_ && requestedDirection_!=9){

		while(modified==false && move<speed ){
			modifiedSpeed=speed;
			while(modified==false && modifiedSpeed!=0){
				
				switch (requestedDirection_){
					
					case 0 : // right
						newPosX = getPosX()+modifiedSpeed;
						newPosY = getPosY();
						break; 

					case 1 :  // left
						newPosX = getPosX()-modifiedSpeed;
						newPosY = getPosY();
						break;

					case 2 :  //up
						newPosX = getPosX();
						newPosY = getPosY()-modifiedSpeed;
						break;

					case 3 : //down
						newPosX = getPosX();
						newPosY = getPosY()+modifiedSpeed;
						break;
				}

				if( !g->checkColision(newPosX,newPosY)){
						changePosition(newPosX, newPosY);
						modified=true;
						direction_=requestedDirection_;					
					}
					

				g->checkBonusEating();
				--modifiedSpeed;
			}
				

			if(!modified){
				++move;
				
				switch (direction_){

				case 0 : // right
					newPosX = getPosX()+1;
					newPosY = getPosY();
					break; 

				case 1 :  // left
					newPosX = getPosX()-1;
					newPosY = getPosY();
					break;

				case 2 :  //up
					newPosX = getPosX();
					newPosY = getPosY()-1;
					break;

				case 3 : //down
					newPosX = getPosX();
					newPosY = getPosY()+1;
					break;
				}


				if(newPosX>=671){
					changePosition(0, newPosY);						
				}

				else if (newPosX<0){
					changePosition(671, newPosY);					
				}

				else if(newPosY>=748){
					changePosition(newPosX, 0);					
				}

				else if(newPosY<=0){
					changePosition(newPosX, 749);					
				}



				else {
					if( !g->checkColision(newPosX,newPosY))
						changePosition(newPosX, newPosY);
				}
				g->checkBonusEating();
			}

				
		}

	}
			
	if (!modified && move<speed) {

		modifiedSpeed=speed;

		while(modified==false && modifiedSpeed!=0){

			switch (direction_){

				case 0 : // right
					newPosX = getPosX()+(modifiedSpeed-move);
					newPosY = getPosY();
					break; 

				case 1 :  // left
					newPosX = getPosX()-(modifiedSpeed-move);
					newPosY = getPosY();
					break;

				case 2 :  //up
					newPosX = getPosX();
					newPosY = getPosY()-(modifiedSpeed-move);
					break;

				case 3 : //down
					newPosX = getPosX();
					newPosY = getPosY()+(modifiedSpeed-move);
					break;
			}

			if(newPosX>=671){
				changePosition(0, newPosY);	
				modified=true;
			}

			else if (newPosX<0){
				changePosition(672, newPosY);
				modified=true;
			}

			else if(newPosY>=748){
				changePosition(newPosX, 0);
				modified=true;
			}

			else if(newPosY<=0){
				changePosition(newPosX, 749);
				modified=true;
			}


			else{ 
				if( !g->checkColision(newPosX,newPosY)){
					changePosition(newPosX, newPosY);
					modified=true;
				}
			}		
			--modifiedSpeed;
			g->checkBonusEating();
		}


	}
	currentState_->decrementRemainingMovement();


}


void Pacman::calculateNextDirection(){}



void Pacman::setDirection(int direction){
	requestedDirection_=direction;
}


void Pacman::changeStateHunter(){
	currentState_=hunterState_;
	currentState_->addRemainingMovement(200);
}

void Pacman::changeStatePrey(){
	currentState_=preyState_;
}

bool Pacman::canEatGhost(){
	return currentState_->canEatGhost();
}
