#include <Pacman.hpp>
#include <GameEngine.hpp>
#include <iostream>

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

	requestedDirection_=9;

	
}

SDL_Texture* Pacman::getCharacterTexture(){

	if(open_<=4){
		open_+=1;
		return characterTexture_;
	}

	else{
		if (open_ == 8)
			open_=0;
		else
			open_+=1;
	
		switch (direction_){
			case 0 : // right
				return characterTextureOpenRight_;
				break; 
			case 1 :  // left
				return characterTextureOpenLeft_;
				break;
			case 2 :  //up
				return characterTextureOpenTop_;
				break;
			case 3 : //down
				break;
		}
		return characterTextureOpenBot_;


	}
}


void Pacman::destroySDLElements(){
	SDL_DestroyTexture(characterTexture_);
	SDL_FreeSurface(characterSurface_);

	SDL_DestroyTexture(characterTextureOpenBot_);
	SDL_FreeSurface(characterSurfaceOpenBot_);

	SDL_DestroyTexture(characterTextureOpenLeft_);
	SDL_FreeSurface(characterSurfaceOpenLeft_);

	SDL_DestroyTexture(characterTextureOpenRight_);
	SDL_FreeSurface(characterSurfaceOpenRight_);

	SDL_DestroyTexture(characterTextureOpenTop_);
	SDL_FreeSurface(characterSurfaceOpenTop_);
}



void Pacman::moveCharacter(GameEngine* g, int speed){

	int modifiedSpeed = speed;
	bool modified=false;


	if(requestedDirection_!=direction_){


		while(modified==false && modifiedSpeed!=0){

				int newPosX, newPosY;		
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
				--modifiedSpeed;
			}

	}

	if (!modified) {

		modifiedSpeed=speed;

		while(modified==false && modifiedSpeed!=0){

			int newPosX, newPosY;		
			switch (direction_){

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

			if(newPosX>=680){
				changePosition(0, newPosY);	
				modified=true;
			}

			else if (newPosX<0){
				changePosition(680, newPosY);
				modified=true;
			}

			else if(newPosY>=755){
				changePosition(newPosX, 0);
				modified=true;
			}

			else if(newPosY<=0){
				changePosition(newPosX, 755);
				modified=true;
			}


			else{ 
				if( !g->checkColision(newPosX,newPosY)){
					changePosition(newPosX, newPosY);
					modified=true;
				}
			}		
			--modifiedSpeed;
		}


	}


}


void Pacman::calculateNextDirection(){}



void Pacman::setDirection(int direction){
	requestedDirection_=direction;
}