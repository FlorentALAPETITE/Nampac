#include <GameEngine.hpp>

#include <Wall.hpp>
#include <Lane.hpp>
#include <memory>
#include <MapReader.hpp>


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

    pacman_ = unique_ptr<Pacman>(new Pacman("sprites/pacmanClose.bmp",5,15*25,17*25,renderer_));   

     
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


	if( !checkColision(newPosX,newPosY)){		
		c->changePosition(newPosX, newPosY);	
	}
	
	renderCharacter(c);
}




void GameEngine::changePacmanDirection(int direction){
	pacman_->setDirection(direction);
}





void GameEngine::createMap(std::vector<std::vector<int>> const& laby){

	
	
	for (unsigned int l = 0; l < laby.size(); ++l)
	{
		mapElements_.push_back(vector<shared_ptr<MapElement>>());
		for (unsigned int c = 0; c < laby[0].size(); ++c)
		{
			if (laby[l][c] == 0){
				mapElements_[l].push_back(shared_ptr<Lane> (new Lane(c*25,l*25,renderer_)));			
				
			}
			else{
				mapElements_[l].push_back(shared_ptr<Wall> (new Wall(c*25,l*25,renderer_)));				
			}
		}
	}

	
}


void GameEngine::renderMap(){

	for (unsigned int l = 0; l < mapElements_.size(); ++l){
		for (unsigned int c = 0; c < mapElements_[0].size(); ++c){
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



shared_ptr<MapElement> GameEngine::getMapElement(int x, int y){	
	return mapElements_[y/25][x/25];
}

bool GameEngine::checkColision(int x, int y){	
	return ! getMapElement(x, y)->canBeCrossed();
}


void GameEngine::destroySDL(){

	for (unsigned int l = 0; l < mapElements_.size(); ++l){
		for (unsigned int c = 0; c < mapElements_[0].size(); ++c){
			mapElements_.at(l).at(c)->destroySDLElements();
		}
	}


	SDL_DestroyRenderer(renderer_); 
	pacman_->destroySDLElements();
    SDL_DestroyWindow(window_);
}




void GameEngine::launchNampac(const char* mapLocation){
	 
        SDL_Event events;
        bool quit(false);
        
        vector<vector<int>> laby = MapReader::BuildMap(mapLocation);

        createMap(laby); 
        
        // While window isn't close
        while(!quit){   

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
            clearRenderer();
            renderMap(); 
            renderCharacter(pacman_.get());
            moveCharacter(pacman_.get());
            renderPresent();



            //Thread test
            //std::this_thread::sleep_for (std::chrono::milliseconds(25));   

            SDL_Delay(25);       



        }   

        destroySDL();
}