#include <GameEngine.hpp>

#include <Wall.hpp>
#include <Lane.hpp>
#include <memory>
#include <MapReader.hpp>
#include <RedGhost.hpp>
#include <BlueGhost.hpp>
#include <OrangeGhost.hpp>
#include <PinkGhost.hpp>
#include <math.h>
#include <stdlib.h>    



using namespace std;


GameEngine::GameEngine(){
	    
           
       
    // SDL initialization 
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        throw string(SDL_GetError());       
    }
        
   
    //Window initialization
    window_ = SDL_CreateWindow("Nampac", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 700, 775, SDL_WINDOW_SHOWN);

    if(window_ == 0)
    {
        throw string(SDL_GetError());        
    }

    renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED); 


    pacman_ = unique_ptr<Pacman>(new Pacman((char*)"sprites/pacmanClose.bmp",5,14*sizeSprite,17*sizeSprite,renderer_)); 


    ghosts_ = vector<unique_ptr<Ghost>>();

    ghosts_.push_back(unique_ptr<RedGhost>(new RedGhost(1*sizeSprite,1*sizeSprite,renderer_)));
   	ghosts_.push_back(unique_ptr<OrangeGhost>(new OrangeGhost(1*sizeSprite,29*sizeSprite,renderer_)));
    ghosts_.push_back(unique_ptr<BlueGhost>(new BlueGhost(26*sizeSprite,1*sizeSprite,renderer_)));
    ghosts_.push_back(unique_ptr<PinkGhost>(new PinkGhost(26*sizeSprite,29*sizeSprite,renderer_)));

    randNumber_ = 0;

    gameOver_=false;
     
}




void GameEngine::renderCharacter(Character* c){
		    
 	SDL_RenderCopy(renderer_,c->getCharacterTexture(),NULL,c->getTextureRect()); // Copie du sprite grâce au SDL_Renderer	 
			

}



void GameEngine::renderCharacters(){
	renderCharacter(pacman_.get());

	for(unsigned int i=0;i<ghosts_.size();++i){
		renderCharacter(ghosts_.at(i).get());
	}
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


	if(newPosX>=680){
		c->changePosition(0, newPosY);	
	}

	else if (newPosX<=0){
		c->changePosition(680, newPosY);
	}

	else {
		if( !checkColision(newPosX,newPosY))
			c->changePosition(newPosX, newPosY);	
	}	
	
		
}

void GameEngine::checkAllCharactersColision(){	
	for(unsigned int i=0;i<ghosts_.size();++i){
		if (checkColisionCharacters(ghosts_.at(i)->getTextureRect(), pacman_->getTextureRect())){
			gameOver_ = true;
		}
	}
}

void GameEngine::moveCharacters(){
	moveCharacter(pacman_.get());

	for(unsigned int i=0;i<ghosts_.size();++i){
		srand(randNumber_);
		randNumber_+=100;
		ghosts_.at(i)->calculateNextDirection();
		moveCharacter(ghosts_.at(i).get());
	}
	
}

void GameEngine::changePacmanDirection(int direction){
	int newPosX, newPosY;

	switch(direction){
		case 0 : // right
			newPosX = pacman_->getPosX()+pacman_->getSpeed();
			newPosY = pacman_->getPosY();
			break; 
		case 1 :  // left
			newPosX = pacman_->getPosX()-pacman_->getSpeed();
			newPosY = pacman_->getPosY();
			break;

		case 2 :  //up
			newPosX = pacman_->getPosX();
			newPosY = pacman_->getPosY()-pacman_->getSpeed();
			break;

		case 3 : //down
			newPosX = pacman_->getPosX();
			newPosY = pacman_->getPosY()+pacman_->getSpeed();
			break;
	}
	if(!checkColision(newPosX,newPosY)){
		pacman_->setDirection(direction);
	}
}

void GameEngine::createMap(vector<vector<int>> const& laby){

	mapElements_ = vector<vector<shared_ptr<MapElement>>> ();

	for (unsigned int l = 0; l < laby.size(); ++l)
	{
		mapElements_.push_back(vector<shared_ptr<MapElement>>());
		for (unsigned int c = 0; c < laby[0].size(); ++c)
		{
			if (laby[l][c] == 0){
				mapElements_[l].push_back(shared_ptr<Lane> (new Lane(c*sizeSprite,l*sizeSprite,renderer_)));			
				
			}
			else{
				mapElements_[l].push_back(shared_ptr<Wall> (new Wall(c*sizeSprite,l*sizeSprite,renderer_)));				
			}
		}
	}
}

void GameEngine::renderMap(){
	Bonus* bonus;
	for (unsigned int l = 0; l < mapElements_.size(); ++l){
		for (unsigned int c = 0; c < mapElements_[0].size(); ++c){
			SDL_RenderCopy(renderer_, mapElements_.at(l).at(c)->getMapElementTexture(), NULL, mapElements_.at(l).at(c)->getTextureRect());
			bonus = mapElements_.at(l).at(c)->getBonus();
			if(bonus!=nullptr){				
				SDL_RenderCopy(renderer_, bonus->getTexture(), NULL, bonus->getTextureRect());
			}
		}
	}
}

void GameEngine::clearRenderer(){
	SDL_RenderClear(renderer_);
}

void GameEngine::renderPresent(){
	SDL_RenderPresent(renderer_);
}

int GameEngine::getSizeSprite(){ return sizeSprite; }

shared_ptr<MapElement> GameEngine::getMapElement(int x, int y){		
	return mapElements_[y][x];
}

bool GameEngine::checkColision(int x, int y){
	int x1 = x/sizeSprite;
   	int y1 = y/sizeSprite;
   	int x2 = (x + sizeSprite -1 ) /sizeSprite;  
   	int y2 = (y + sizeSprite -1 ) /sizeSprite;
   	for(int i = x1; i <=x2; ++i)
   	{
    	for(int j = y1; j<=y2; ++j)
    	{
        	if (!getMapElement(i,j)->canBeCrossed())
            	return true;
    	}
  	}
	return false;
}

bool GameEngine::checkColisionCharacters(SDL_Rect* c1, SDL_Rect* c2){
	if(
		(c2->x >= c1->x + c1->w) || // too right
		(c2->x + c2->w <= c1->x) || // too left
		(c2->y >= c1->y + c1->h) || // too down
		(c2->y + c2->h <= c1->y) // too top
		){
		return false;
	}
	return true;

}

void GameEngine::destroySDL(){

	for (unsigned int l = 0; l < mapElements_.size(); ++l){
		for (unsigned int c = 0; c < mapElements_[0].size(); ++c){
			mapElements_.at(l).at(c)->destroySDLElements();
		}
	}


	SDL_DestroyRenderer(renderer_); 
	pacman_->destroySDLElements();

	for(unsigned int i=0;i<ghosts_.size();++i){
		ghosts_.at(i).get()->destroySDLElements();
	}

	SDL_DestroyTexture(gameOverTexture_);
	SDL_FreeSurface(gameOverSurface_);

    SDL_DestroyWindow(window_);



}



void GameEngine::printGameOverMessage(){
	TTF_Init();

	TTF_Font* xolo = TTF_OpenFont("./font/Xolonium-Regular.ttf", 250); 

	SDL_Color White = {255, 0, 0};  

	gameOverSurface_ = TTF_RenderText_Solid(xolo, "GAME OVER", White); 

	gameOverTexture_ = SDL_CreateTextureFromSurface(renderer_, gameOverSurface_); 

	gameOverRect_ = {150,250,400,200};
	
	SDL_RenderCopy(renderer_, gameOverTexture_, NULL, &gameOverRect_); 
}





void GameEngine::launchNampac(const char* mapLocation){
	 
        SDL_Event events;
        bool quit(false);
        
        vector<vector<int>> laby = MapReader::BuildMap(mapLocation);

        createMap(laby); 

        renderMap(); 
        renderCharacters();
        renderPresent();

        // While window isn't close
        while(!quit && !gameOver_){   

            while (SDL_PollEvent(&events)) {

                if(events.window.event == SDL_WINDOWEVENT_CLOSE)
                    quit = true;

                // arrow key events
                switch( events.key.keysym.sym ){ 
                    case SDLK_UP: 
                        changePacmanDirection(2);
                        break;
                    case SDLK_DOWN:
                        changePacmanDirection(3);
                        break;
                    case SDLK_RIGHT:
                        changePacmanDirection(0);
                        break;
                    case SDLK_LEFT:
                        changePacmanDirection(1);
                        break;

                  }           
              }
            moveCharacters(); 
            clearRenderer();
            renderMap(); 
            renderCharacters();
            renderPresent();
            checkAllCharactersColision();
                       
            


            if(gameOver_){
            	printGameOverMessage();
            	renderPresent();
            	SDL_Delay(5000);
            }




            //Thread test
            //std::this_thread::sleep_for (std::chrono::milliseconds(25));   

            //SDL_Delay(25);       



        }   

        destroySDL();
}