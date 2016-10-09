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

    pacman_ = new Pacman("sprites/pacmanClose.bmp",3,0,0,renderer_);   

 //    // REFACTO DANS CLASSES MURS/COULOIRS
 //    mapRenderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED); 

 //    pSMurs = SDL_LoadBMP(cheminMurs);
	// pSSol = SDL_LoadBMP(cheminSol);
	// if(!pSSol || !pSMurs)
	// 	throw std::string("Erreur creéation Sprite");

	// pTMurs = SDL_CreateTextureFromSurface(mapRenderer_, pSMurs);
	// pTSol = SDL_CreateTextureFromSurface(mapRenderer_, pSSol);
	// if(!pTSol || !pTMurs)
	// 	throw std::string("Erreur creéation texture");
	// // REFACTO HERE

    
}


SDL_Window* GameEngine::getWindow(){
	return window_;
}


void GameEngine::setBackgroundBlack(){
	SDL_SetRenderDrawColor(renderer_, 0, 0, 0, 255);
	//SDL_RenderClear(renderer_);
	SDL_RenderPresent(renderer_);
}

void GameEngine::renderCharacter(Character* c){
		    
 	SDL_RenderCopy(renderer_,c->getCharacterTexture(),NULL,c->getTextureRect()); // Copie du sprite grâce au SDL_Renderer
	           
	SDL_RenderPresent(renderer_); // Affichage		
	

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




// A MODIFIER --> Tab mur / couloirs
void GameEngine::createMap(std::vector<std::vector<int>> const& laby){

	
	
	for (unsigned int l = 0; l < laby.size(); ++l)
	{
		mapElements_.push_back(vector<MapElement*>());
		for (unsigned int c = 0; c < laby[0].size(); ++c)
		{
			if (laby[l][c] == 0){
				mapElements_[l].push_back(new MapElement("sprites/lane.bmp",c*25,l*25,renderer_));			
				
			}
			else{
				mapElements_[l].push_back(new MapElement("sprites/wall.bmp",c*25,l*25,renderer_));				
			}
		}
	}

	
}

// A MODIFIER
void GameEngine::renderMap(){

	for (unsigned int l = 0; l < mapElements_.size(); ++l)
	{
		for (unsigned int c = 0; c < mapElements_[0].size(); ++c)
		{
			SDL_RenderCopy(renderer_, mapElements_.at(l).at(c)->getMapElementTexture(), NULL, mapElements_.at(l).at(c)->getTextureRect());


		}
	}

	
}


void GameEngine::clearRenderer(){
	SDL_RenderClear(renderer_);
}


void GameEngine::renderPresent(){
	SDL_RenderPresent(renderer_);
}
