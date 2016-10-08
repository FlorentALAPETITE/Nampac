#include <GameEngine.hpp>


using namespace std;


GameEngine::GameEngine(){
	    
           
       
    // SDL initialization 
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        throw string(SDL_GetError());       
    }
        
   
    //Window initialization
    window_ = SDL_CreateWindow("Test SDL 2.0", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 800, SDL_WINDOW_SHOWN);

    if(window_ == 0)
    {
        throw string(SDL_GetError());        
    }

    renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED); 

    pacman_ = new Pacman("sprites/pacmanClose.bmp",1,0,0,renderer_);   


    
}


SDL_Window* GameEngine::getWindow(){
	return window_;
}


void GameEngine::setBackgroundBlack(){
	SDL_SetRenderDrawColor(renderer_, 0, 0, 0, 255);
	SDL_RenderClear(renderer_);
	SDL_RenderPresent(renderer_);
}

void GameEngine::renderCharacter(Character* c){
		    
 	SDL_RenderCopy(renderer_,c->getCharacterTexture(),NULL,c->getTextureRect()); // Copie du sprite grâce au SDL_Renderer
	           
	SDL_RenderPresent(renderer_); // Affichage	
	SDL_RenderClear(renderer_);
	

}




void GameEngine::moveCharacter(Character * c){
	int newPosX, newPosY;

	switch (c->getDirection()){
		case 0 : // right
			newPosX = c->getPosX()+c->getSpeed();
			newPosY = c->getPosY();
			break; 
		case 1 :  // left
			newPosX = c->getPosX()-c->getSpeed();
			newPosY = c->getPosY();
			break;
		case 2 :  //up
			newPosX = c->getPosX();
			newPosY = c->getPosY()-c->getSpeed();
			break;
		case 3 : //down
			newPosX = c->getPosX();
			newPosY = c->getPosY()+c->getSpeed();
			break;
	}
	c->changePosition(newPosX, newPosY);
	renderCharacter(c);
}


void GameEngine::destroyRenderer(){
	SDL_DestroyRenderer(renderer_); 
}

Pacman* GameEngine::getPacman(){
	return pacman_;
}

void GameEngine::changePacmanDirection(int direction){
	pacman_->setDirection(direction);
}