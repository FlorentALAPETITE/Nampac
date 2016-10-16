#include <GameEngine.hpp>

#include <Wall.hpp>
#include <Lane.hpp>
#include <memory>
#include <MapReader.hpp>
#include <RedGhost.hpp>
#include <math.h>



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

    pacman_ = unique_ptr<Pacman>(new Pacman("sprites/pacmanClose.bmp",5,15*sizeSprite,17*sizeSprite,renderer_)); 

    ghosts_ = vector<unique_ptr<Ghost>>();

    ghosts_.push_back(unique_ptr<RedGhost>(new RedGhost(1*25,1*25,renderer_)));

     
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
	int newPosX, newPosY, checkX, checkY;


		switch (c->getDirection()){

		case 0 : // right
			newPosX = c->getPosX()+c->getSpeed();
			newPosY = c->getPosY();

			checkX = newPosX+sizeSprite-1;
			checkY = newPosY;

			break; 

		case 1 :  // left
			newPosX = c->getPosX()-c->getSpeed();
			newPosY = c->getPosY();

			checkX = newPosX;
			checkY = newPosY;


			break;

		case 2 :  //up
			newPosX = c->getPosX();
			newPosY = c->getPosY()-c->getSpeed();

			checkX = newPosX;
			checkY = newPosY;

			break;

		case 3 : //down
			newPosX = c->getPosX();
			newPosY = c->getPosY()+c->getSpeed();

			checkX = newPosX;
			checkY = newPosY+sizeSprite-1;
			
			break;
	}


	if( !checkColision(checkX,checkY)){		
		c->changePosition(newPosX, newPosY);	
	}		
	
}



void GameEngine::moveCharacters(){
	moveCharacter(pacman_.get());

	for(unsigned int i=0;i<ghosts_.size();++i){
		ghosts_.at(i)->calculateNextDirection();
		moveCharacter(ghosts_.at(i).get());
	}
	
}




void GameEngine::changePacmanDirection(int direction){
	pacman_->setDirection(direction);
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



// shared_ptr<MapElement> GameEngine::getMapElement(int x, int y){
// 	int xRes = x/sizeSprite;
// 	int yRes = y/sizeSprite;
// 	// ex: 25/25 == case 1 != case 0
// 	if(x % 25 == 0)
// 		xRes = xRes - 1;
	
// 	if(y % 25 == 0)
// 		yRes = yRes - 1;

// 	return mapElements_[yRes][xRes];
// }




// bool GameEngine::checkColision(int x, int y){	
// 	cout << "x: "<< x << " y: " << y << "  " << !getMapElement(x, y)->canBeCrossed()<< endl;
// 	return !getMapElement(x, y)->canBeCrossed();
// }




shared_ptr<MapElement> GameEngine::getMapElement(int x, int y){		
	return mapElements_[ceil(y/sizeSprite)][ceil(x/sizeSprite)];
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




bool GameEngine::checkColisionCaracters(SDL_Rect* c1, SDL_Rect* c2){
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
            renderCharacters();
            moveCharacters();            
            renderPresent();




            //Thread test
            //std::this_thread::sleep_for (std::chrono::milliseconds(25));   

            SDL_Delay(25);       



        }   

        destroySDL();
}